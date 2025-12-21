#include "win32utils.h"
#include "config.h"
#include <Psapi.h>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QMap>
#include <QFile>
#include <vector>

// Static icon cache to avoid repeated icon fetching
static QMap<HWND, QIcon> s_iconCache;

void Win32Utils::logWin32Error(const QString &functionName)
{
    DWORD errorCode = GetLastError();
    logWin32Error(functionName, errorCode);
}

void Win32Utils::logWin32Error(const QString &functionName, DWORD errorCode)
{
    if (errorCode != 0)
    {
        qWarning() << "Win32 API Error in" << functionName << "- Error code:" << errorCode;
    }
}

bool Win32Utils::isValidWindow(HWND hwnd)
{
    return hwnd != nullptr && IsWindow(hwnd);
}

bool Win32Utils::openProcessAndGetModule(DWORD processId, HANDLE &hProcess, HMODULE &hModule)
{
    hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
    if (!hProcess)
    {
        DWORD error = GetLastError();
        // Don't log for access denied errors as they're common for system processes
        if (error != ERROR_ACCESS_DENIED)
        {
            logWin32Error("OpenProcess", error);
        }
        return false;
    }

    DWORD cbNeeded;
    if (!EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded))
    {
        logWin32Error("EnumProcessModules");
        CloseHandle(hProcess);
        return false;
    }

    return true;
}

QString Win32Utils::getProcessName(DWORD processId)
{
    HANDLE hProcess;
    HMODULE hModule;

    if (!openProcessAndGetModule(processId, hProcess, hModule))
    {
        return "Unknown";
    }

    QString processName = "Unknown";
    WCHAR szProcessName[MAX_PATH] = {0};
    if (GetModuleBaseNameW(hProcess, hModule, szProcessName,
                           sizeof(szProcessName) / sizeof(WCHAR)))
    {
        processName = QString::fromWCharArray(szProcessName);
    }
    else
    {
        logWin32Error("GetModuleBaseNameW");
    }

    if (!CloseHandle(hProcess))
    {
        logWin32Error("CloseHandle");
    }

    return processName;
}

QString Win32Utils::getProcessPath(DWORD processId)
{
    HANDLE hProcess;
    HMODULE hModule;

    if (!openProcessAndGetModule(processId, hProcess, hModule))
    {
        return QString();
    }

    QString processPath;
    WCHAR szProcessPath[MAX_PATH] = {0};
    if (GetModuleFileNameExW(hProcess, hModule, szProcessPath,
                             sizeof(szProcessPath) / sizeof(WCHAR)))
    {
        processPath = QString::fromWCharArray(szProcessPath);
    }
    else
    {
        logWin32Error("GetModuleFileNameExW");
    }

    if (!CloseHandle(hProcess))
    {
        logWin32Error("CloseHandle");
    }

    return processPath;
}

HICON Win32Utils::tryGetIconViaMessage(HWND hwnd, WPARAM iconType)
{
    DWORD_PTR result = 0;
    // Use SendMessageTimeout to avoid freezing when the target window is unresponsive
    // SMTO_ABORTIFHUNG: Returns immediately if the target window is hung
    // SMTO_BLOCK: Prevents the calling thread from processing other requests while waiting
    if (SendMessageTimeout(hwnd, WM_GETICON, iconType, 0,
                          SMTO_ABORTIFHUNG | SMTO_BLOCK, 200, &result))
    {
        return (HICON)result;
    }
    return nullptr;
}

HICON Win32Utils::tryGetIconViaClassLongPtr(HWND hwnd, int index)
{
    HICON hIcon = (HICON)GetClassLongPtr(hwnd, index);
    if (!hIcon && GetLastError() != 0)
    {
        QString indexName = (index == GCLP_HICON) ? "GCLP_HICON" : "GCLP_HICONSM";
        logWin32Error("GetClassLongPtr(" + indexName + ")");
    }
    return hIcon;
}

QIcon Win32Utils::convertHIconToQIcon(HICON hIcon)
{
    if (!hIcon)
    {
        return QIcon();
    }
    QPixmap pixmap = QPixmap::fromImage(QImage::fromHICON(hIcon));
    return QIcon(pixmap);
}

QIcon Win32Utils::getWindowIcon(HWND hwnd)
{
    if (!isValidWindow(hwnd))
    {
        qWarning() << "getWindowIcon: Invalid window handle";
        return QIcon();
    }

    // Check cache first
    if (s_iconCache.contains(hwnd))
    {
        return s_iconCache.value(hwnd);
    }

    // Try different methods to get the icon
    HICON hIcon = tryGetIconViaMessage(hwnd, ICON_BIG);
    if (!hIcon)
    {
        hIcon = tryGetIconViaMessage(hwnd, ICON_SMALL);
    }
    if (!hIcon)
    {
        hIcon = tryGetIconViaClassLongPtr(hwnd, GCLP_HICON);
    }
    if (!hIcon)
    {
        hIcon = tryGetIconViaClassLongPtr(hwnd, GCLP_HICONSM);
    }

    QIcon icon = convertHIconToQIcon(hIcon);

    // Cache the result (even if empty)
    s_iconCache.insert(hwnd, icon);

    return icon;
}

QString Win32Utils::getWindowTitle(HWND hwnd, bool *success)
{
    if (success)
    {
        *success = false;
    }

    if (!isValidWindow(hwnd))
    {
        qWarning() << "getWindowTitle: Invalid window handle";
        return QString();
    }

    // Use MAX_TITLE_LENGTH from config
    int maxLen = WinSelectorConfig::WindowScanner::maxTitleLength();
    std::vector<WCHAR> title(maxLen + 1, 0);

    int length = GetWindowTextW(hwnd, title.data(), maxLen + 1);

    if (length == 0)
    {
        DWORD error = GetLastError();
        // Empty title is not necessarily an error
        if (error != 0)
        {
            logWin32Error("GetWindowTextW", error);
        }
        return QString();
    }

    if (success)
    {
        *success = true;
    }

    return QString::fromWCharArray(title.data());
}

bool Win32Utils::activateWindow(HWND hwnd)
{
    if (!isValidWindow(hwnd))
    {
        qWarning() << "activateWindow: Invalid window handle";
        return false;
    }

    // Restore window if it's minimized
    if (IsIconic(hwnd))
    {
        if (!ShowWindow(hwnd, SW_RESTORE))
        {
            logWin32Error("ShowWindow(SW_RESTORE)");
            // Continue anyway, as SetForegroundWindow might still work
        }
    }

    if (!SetForegroundWindow(hwnd))
    {
        logWin32Error("SetForegroundWindow");
        return false;
    }

    return true;
}

bool Win32Utils::closeWindow(HWND hwnd)
{
    if (!isValidWindow(hwnd))
    {
        qWarning() << "closeWindow: Invalid window handle";
        return false;
    }

    // PostMessage returns 0 on failure, non-zero on success
    if (!PostMessage(hwnd, WM_CLOSE, 0, 0))
    {
        logWin32Error("PostMessage(WM_CLOSE)");
        return false;
    }

    return true;
}

bool Win32Utils::launchProcess(const QString &processPath)
{
    if (processPath.isEmpty())
    {
        qWarning() << "launchProcess: Empty process path";
        return false;
    }

    // Check if the executable file exists
    if (!QFile::exists(processPath))
    {
        qWarning() << "launchProcess: File does not exist:" << processPath;
        return false;
    }

    SHELLEXECUTEINFOW shellExecInfo = {0};
    shellExecInfo.cbSize = sizeof(SHELLEXECUTEINFOW);
    shellExecInfo.fMask = SEE_MASK_DEFAULT;
    shellExecInfo.lpVerb = L"open";
    shellExecInfo.lpFile = reinterpret_cast<LPCWSTR>(processPath.utf16());
    shellExecInfo.nShow = SW_SHOWNORMAL;

    if (!ShellExecuteExW(&shellExecInfo))
    {
        logWin32Error("ShellExecuteExW");
        return false;
    }

    return true;
}

void Win32Utils::clearIconCache(HWND hwnd)
{
    if (hwnd == nullptr)
    {
        // Clear entire cache
        s_iconCache.clear();
    }
    else
    {
        // Clear specific window from cache
        s_iconCache.remove(hwnd);
    }
}

HWND Win32Utils::getForegroundWindow()
{
    return GetForegroundWindow();
}

bool Win32Utils::registerHotKey(HWND hwnd, int id, UINT modifiers, UINT vk)
{
    if (!RegisterHotKey(hwnd, id, modifiers, vk))
    {
        logWin32Error("RegisterHotKey");
        return false;
    }
    return true;
}

bool Win32Utils::unregisterHotKey(HWND hwnd, int id)
{
    if (!UnregisterHotKey(hwnd, id))
    {
        logWin32Error("UnregisterHotKey");
        return false;
    }
    return true;
}
