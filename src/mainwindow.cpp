#include "mainwindow.h"
#include "flowlayout.h"
#include "windowtile.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "win32utils.h"
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <algorithm>
#include <QMap>
#include <QMenu>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUi();
    createTrayIcon();

    m_refreshTimer = new QTimer(this);
    connect(m_refreshTimer, &QTimer::timeout, this, &MainWindow::refreshWindows);
    m_refreshTimer->start(WinSelectorConfig::MainWindow::refreshIntervalMs());

    refreshWindows();

    // Register global hotkey (Home key)
    // ID 1 for toggle visibility
    Win32Utils::registerHotKey((HWND)winId(), 1, 0, Settings::instance().getToggleVisibilityKeyVk());
}

MainWindow::~MainWindow() 
{ 
    Win32Utils::unregisterHotKey((HWND)winId(), 1);
    delete ui; 
}

void MainWindow::setupUi()
{
    // Window flags
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    // Layout
    m_containerWidget = new QWidget(this);
    m_flowLayout = new FlowLayout(m_containerWidget,
                                  WinSelectorConfig::Layout::margin(),
                                  WinSelectorConfig::Layout::hSpacing(),
                                  WinSelectorConfig::Layout::vSpacing());
    m_flowLayout->setRTL(true);
    setCentralWidget(m_containerWidget);

    // Position on right edge of target screen
    QScreen *screen = getTargetScreen();
    QRect screenGeom = screen->geometry();
    setGeometry(screenGeom.width() - WinSelectorConfig::MainWindow::initialWidth(),
                screenGeom.y(),
                WinSelectorConfig::MainWindow::initialWidth(),
                screenGeom.height());
}

void MainWindow::refreshWindows()
{
    QList<WindowInfo> windows = fetchAndSortWindows();
    updateTiles(windows);
    adjustWindowGeometry();
}

QList<WindowInfo> MainWindow::fetchAndSortWindows()
{
    QList<WindowInfo> windows = WindowScanner::getWindows();

    // Sort by process name first, then by window title
    std::sort(windows.begin(), windows.end(),
              [](const WindowInfo &a, const WindowInfo &b)
              {
                  if (a.processName != b.processName)
                  {
                      return a.processName < b.processName;
                  }
                  return a.title < b.title;
              });

    return windows;
}

void MainWindow::updateTiles(const QList<WindowInfo> &windows)
{
    // Map existing tiles by HWND for reuse
    QMap<HWND, WindowTile *> existingTiles;
    QLayoutItem *item;
    while ((item = m_flowLayout->takeAt(0)))
    {
        if (WindowTile *tile = qobject_cast<WindowTile *>(item->widget()))
        {
            existingTiles.insert(tile->getInfo().hwnd, tile);
        }
        else if (item->widget())
        {
            // Delete any non-WindowTile widgets (shouldn't happen normally)
            delete item->widget();
        }
        delete item;
    }

    // Re-populate layout with current windows
    HWND foregroundHwnd = Win32Utils::getForegroundWindow();

    for (const WindowInfo &info : windows)
    {
        WindowTile *tile = nullptr;
        if (existingTiles.contains(info.hwnd))
        {
            // Reuse existing tile
            tile = existingTiles.take(info.hwnd);
            tile->setInfo(info);
            tile->setVisible(true);
        }
        else
        {
            // Create new tile for new window
            tile = new WindowTile(info, this);
            connect(tile, &WindowTile::activated, this, &MainWindow::activateWindow);
            connect(tile, &WindowTile::closed, this, &MainWindow::closeWindow);
        }

        // Apply shift+click close setting
        tile->setEnableShiftClickClose(WinSelectorConfig::WindowTile::enableShiftClickClose());
        tile->setActive(info.hwnd == foregroundHwnd);
        m_flowLayout->addWidget(tile);
    }

    // Delete tiles for windows that no longer exist
    for (WindowTile *tile : existingTiles)
    {
        // Clear icon cache for closed windows
        Win32Utils::clearIconCache(tile->getInfo().hwnd);
        delete tile;
    }
}

void MainWindow::adjustWindowGeometry()
{
    QScreen *screen = getTargetScreen();
    QRect availableGeom = screen->availableGeometry();
    int requiredWidth = m_flowLayout->totalWidthForHeight(availableGeom.height());

    // Ensure minimum width to avoid tiny window when empty
    if (requiredWidth < WinSelectorConfig::MainWindow::minimumWidth())
    {
        requiredWidth = WinSelectorConfig::MainWindow::minimumWidth();
    }

    setGeometry(availableGeom.x() + availableGeom.width() - requiredWidth,
                availableGeom.y(),
                requiredWidth,
                availableGeom.height());

    // Force layout update even if size didn't change
    m_flowLayout->setGeometry(m_containerWidget->rect());
}

void MainWindow::activateWindow(HWND hwnd)
{
    Win32Utils::activateWindow(hwnd);
}

void MainWindow::closeWindow(HWND hwnd)
{
    Win32Utils::closeWindow(hwnd);
    // Clear icon cache for this window
    Win32Utils::clearIconCache(hwnd);
    // Refresh after a short delay
    QTimer::singleShot(WinSelectorConfig::MainWindow::closeRefreshDelayMs(),
                       this, &MainWindow::refreshWindows);
}

void MainWindow::createTrayIcon()
{
    m_trayIcon = new QSystemTrayIcon(this);
    m_trayIcon->setIcon(QIcon(":/icon.ico"));

    QMenu *trayMenu = new QMenu(this);
    QAction *quitAction = new QAction(tr("Exit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    trayMenu->addAction(quitAction);

    m_trayIcon->setContextMenu(trayMenu);
    connect(m_trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::onTrayIconActivated);
    m_trayIcon->show();
}

void MainWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
    {
        show();
        raise();
        Win32Utils::activateWindow((HWND)winId());
    }
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    MSG *msg = static_cast<MSG *>(message);
    if (msg->message == WM_HOTKEY)
    {
        if (msg->wParam == 1) // HOTKEY_ID_TOGGLE
        {
            toggleVisibility();
            return true;
        }
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::toggleVisibility()
{
    if (isVisible())
    {
        hide();
    }
    else
    {
        show();
        raise();
        Win32Utils::activateWindow((HWND)winId());
    }
}

QScreen* MainWindow::getTargetScreen()
{
    QList<QScreen*> screens = QGuiApplication::screens();
    int targetIndex = WinSelectorConfig::Display::targetDisplayIndex();
    
    // Return the target screen if the index is valid
    if (targetIndex >= 0 && targetIndex < screens.size())
    {
        return screens[targetIndex];
    }
    
    // Fallback to primary screen if index is out of range
    return QGuiApplication::primaryScreen();
}
