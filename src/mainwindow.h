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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FlowLayout *m_flowLayout;
    QTimer *m_refreshTimer;
    QWidget *m_containerWidget;

    void setupUi();
    void refreshWindows();
    void activateWindow(HWND hwnd);
    void closeWindow(HWND hwnd);

    // Helper methods for refreshWindows()
    QList<WindowInfo> fetchAndSortWindows();
    void updateTiles(const QList<WindowInfo> &windows);
    void adjustWindowGeometry();
    void createTrayIcon();

    QSystemTrayIcon *m_trayIcon;
};
#endif // MAINWINDOW_H
