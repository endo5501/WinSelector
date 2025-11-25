#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "windowscanner.h"
#include <QMainWindow>
#include <QTimer>
#include <QSystemTrayIcon>

class FlowLayout;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief Main application window
 *
 * Handles the display of window tiles, system tray integration, and window management operations.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new MainWindow
     * @param parent Parent widget
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FlowLayout *m_flowLayout;
    QTimer *m_refreshTimer;
    QWidget *m_containerWidget;

    void setupUi();

    /**
     * @brief Refresh the list of open windows
     */
    void refreshWindows();

    /**
     * @brief Activate a specific window
     * @param hwnd Handle of the window to activate
     */
    void activateWindow(HWND hwnd);

    /**
     * @brief Close a specific window
     * @param hwnd Handle of the window to close
     */
    void closeWindow(HWND hwnd);

    // Helper methods for refreshWindows()

    /**
     * @brief Fetch and sort the list of current windows
     * @return List of WindowInfo objects
     */
    QList<WindowInfo> fetchAndSortWindows();

    /**
     * @brief Update the UI tiles with new window information
     * @param windows List of window information
     */
    void updateTiles(const QList<WindowInfo> &windows);

    /**
     * @brief Adjust the window geometry based on content
     */
    void adjustWindowGeometry();

    /**
     * @brief Create and initialize the system tray icon
     */
    void createTrayIcon();

    /**
     * @brief Handle system tray icon activation events
     * @param reason The reason for activation
     */
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

    QSystemTrayIcon *m_trayIcon;
};
#endif // MAINWINDOW_H
