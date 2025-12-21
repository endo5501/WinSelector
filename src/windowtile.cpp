#include "windowtile.h"
#include "config.h"
#include <QAction>
#include <QHBoxLayout>
#include <QMenu>

WindowTile::WindowTile(const WindowInfo &info, QWidget *parent)
    : QWidget(parent), m_info(info)
{
    setupUi();
    setupStyle();
    setCursor(Qt::PointingHandCursor);
    // Set a fixed height for consistency, width can be flexible or fixed
    setFixedHeight(WinSelectorConfig::WindowTile::height());
    setFixedWidth(WinSelectorConfig::WindowTile::width()); // Initial fixed width, can be adjusted
}

QSize WindowTile::sizeHint() const
{
    // Return the fixed size for proper layout calculations
    return QSize(WinSelectorConfig::WindowTile::width(), WinSelectorConfig::WindowTile::height());
}

void WindowTile::setInfo(const WindowInfo &info)
{
    m_info = info;

    if (!m_info.icon.isNull())
    {
        m_iconLabel->setPixmap(m_info.icon.pixmap(WinSelectorConfig::WindowTile::iconSize(), WinSelectorConfig::WindowTile::iconSize()));
    }
    else
    {
        m_iconLabel->setText("?");
    }

    // Calculate available width for title
    // Fixed width - margins(left+right) - spacing - icon
    int availableWidth = WinSelectorConfig::WindowTile::width() - (WinSelectorConfig::WindowTile::contentMargin() * 2) - WinSelectorConfig::WindowTile::internalSpacing() - WinSelectorConfig::WindowTile::iconSize();
    QFontMetrics metrics(m_titleLabel->font());
    QString elidedTitle = metrics.elidedText(m_info.title, Qt::ElideRight, availableWidth);
    m_titleLabel->setText(elidedTitle);
    m_titleLabel->setToolTip(m_info.title);
}

void WindowTile::setupUi()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(WinSelectorConfig::WindowTile::contentMargin(), WinSelectorConfig::WindowTile::contentMargin(), WinSelectorConfig::WindowTile::contentMargin(), WinSelectorConfig::WindowTile::contentMargin());
    layout->setSpacing(WinSelectorConfig::WindowTile::internalSpacing());

    m_iconLabel = new QLabel(this);
    m_iconLabel->setFixedSize(WinSelectorConfig::WindowTile::iconSize(), WinSelectorConfig::WindowTile::iconSize());
    m_iconLabel->setScaledContents(true);

    m_titleLabel = new QLabel(this);

    layout->addWidget(m_iconLabel);
    layout->addWidget(m_titleLabel);

    setInfo(m_info);
}

void WindowTile::setupStyle()
{
    // Basic styling
    setAttribute(Qt::WA_StyledBackground, true);
    
    QString bgColor = m_isActive ? "#E3F2FD" : "#FFFFFF"; // Light Blue for active
    QString borderColor = m_isActive ? "#2196F3" : "#ccc"; // Blue for active
    
    QString style = QString("WindowTile {"
                  "   background-color: %1;"
                  "   border: 1px solid %2;"
                  "   border-radius: 5px;"
                  "}"
                  "WindowTile:hover {"
                  "   background-color: #F0F0F0;"
                  "   border-color: #999;"
                  "}").arg(bgColor, borderColor);

    setStyleSheet(style);
}

void WindowTile::setActive(bool active)
{
    if (m_isActive != active)
    {
        m_isActive = active;
        setupStyle();
    }
}

void WindowTile::setEnableShiftClickClose(bool enabled)
{
    m_enableShiftClickClose = enabled;
}

void WindowTile::showContextMenu(const QPoint &globalPos)
{
    QMenu contextMenu(this);

    // "Launch" menu item
    QAction *launchAction = contextMenu.addAction("起動");
    if (m_info.processPath.isEmpty())
    {
        launchAction->setEnabled(false);  // Disable if path is not available
    }
    connect(launchAction, &QAction::triggered, this,
            [this]()
            { emit launchRequested(m_info.processPath); });

    // "Close Window" menu item
    QAction *closeAction = contextMenu.addAction("ウィンドウを閉じる");
    connect(closeAction, &QAction::triggered, this,
            [this]()
            { emit closed(m_info.hwnd); });

    contextMenu.exec(globalPos);
}

void WindowTile::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        // Check if Shift+Click close mode is enabled
        if (m_enableShiftClickClose && (event->modifiers() & Qt::ShiftModifier))
        {
            emit closed(m_info.hwnd);
        }
        else
        {
            emit activated(m_info.hwnd);
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        showContextMenu(event->globalPosition().toPoint());
    }
}
