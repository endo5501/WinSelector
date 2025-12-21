#include "windowscanner.h"
#include "win32utils.h"
#include <QDebug>

static bool isWindowRelevant(HWND hwnd)
{
    // Only consider visible windows
    if (!IsWindowVisible(hwnd))
    {
        return false;
    }

    // Skip tool windows (like tooltips) unless explicitly marked as app windows
    // Tool windows have WS_EX_TOOLWINDOW flag but not WS_EX_APPWINDOW
    LONG_PTR exStyle = GetWindowLongPtr(hwnd, GWL_EXSTYLE);
    if ((exStyle & WS_EX_TOOLWINDOW) && !(exStyle & WS_EX_APPWINDOW))
    {
        return false;
    }

    // Allow windows with empty titles - we'll show process name instead
    return true;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    QList<WindowInfo> *list = reinterpret_cast<QList<WindowInfo> *>(lParam);

    if (!isWindowRelevant(hwnd))
        return TRUE;

    // Get window title using Win32Utils with error checking
    bool titleSuccess = false;
    QString titleStr = Win32Utils::getWindowTitle(hwnd, &titleSuccess);

    // Skip Program Manager (Desktop)
    if (titleStr == "Program Manager")
        return TRUE;

    DWORD processId = 0;
    GetWindowThreadProcessId(hwnd, &processId);

    WindowInfo info;
    info.hwnd = hwnd;
    info.processId = processId;
    info.processName = Win32Utils::getProcessName(processId);
    info.processPath = Win32Utils::getProcessPath(processId);

    // Use process name if title is empty
    if (titleStr.isEmpty())
    {
        info.title = info.processName;
    }
    else
    {
        info.title = titleStr;
    }

    info.icon = Win32Utils::getWindowIcon(hwnd);

    list->append(info);

    return TRUE;
}

QList<WindowInfo> WindowScanner::getWindows()
{
    QList<WindowInfo> windows;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&windows));
    return windows;
}
