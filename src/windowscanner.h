#ifndef WINDOWSCANNER_H
#define WINDOWSCANNER_H

#include <QList>
#include <QString>
#include <QIcon>
#include <Windows.h>

/**
 * @brief Structure holding information about a window
 */
struct WindowInfo
{
    HWND hwnd;
    QString title;
    QIcon icon;
    QString processName;
    DWORD processId;

    bool operator==(const WindowInfo &other) const
    {
        return hwnd == other.hwnd && title == other.title &&
               processId == other.processId;
    }
};

/**
 * @brief Utility class for scanning open windows
 */
class WindowScanner
{
public:
    /**
     * @brief Get a list of all visible windows
     * @return List of WindowInfo objects for visible windows
     */
    static QList<WindowInfo> getWindows();
};

#endif // WINDOWSCANNER_H
