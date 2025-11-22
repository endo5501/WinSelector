#ifndef WINDOWSCANNER_H
#define WINDOWSCANNER_H

#include <QList>
#include <QString>
#include <QIcon>
#include <Windows.h>

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

class WindowScanner
{
public:
    static QList<WindowInfo> getWindows();
};

#endif // WINDOWSCANNER_H
