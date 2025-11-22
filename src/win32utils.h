#ifndef WIN32UTILS_H
#define WIN32UTILS_H

#include <QString>
#include <QIcon>
#include <windows.h>

/**
 * @brief Utility class for Win32 API operations with proper error checking
 *
 * This class provides static wrapper functions for common Win32 API operations,
 * adding error checking, logging, and safety checks that are missing from raw API calls.
 */
class Win32Utils
{
public:
    /**
     * @brief Get the process name from a process ID
     * @param processId The process ID to query
     * @return Process name, or "Unknown" if the query fails
     */
    static QString getProcessName(DWORD processId);

    /**
     * @brief Get the icon for a window
     * @param hwnd Window handle
     * @return QIcon representing the window's icon, or empty QIcon if none found
     */
    static QIcon getWindowIcon(HWND hwnd);

    /**
     * @brief Get the title of a window with buffer overflow protection
     * @param hwnd Window handle
     * @param success Optional pointer to bool that receives true if successful, false otherwise
     * @return Window title as QString
     */
    static QString getWindowTitle(HWND hwnd, bool *success = nullptr);

    /**
     * @brief Activate (bring to foreground) a window
     * @param hwnd Window handle
     * @return true if successful, false otherwise
     */
    static bool activateWindow(HWND hwnd);

    /**
     * @brief Close a window by sending WM_CLOSE message
     * @param hwnd Window handle
     * @return true if successful, false otherwise
     */
    static bool closeWindow(HWND hwnd);

    /**
     * @brief Check if a window handle is valid
     * @param hwnd Window handle to check
     * @return true if valid, false otherwise
     */
    static bool isValidWindow(HWND hwnd);

    /**
     * @brief Clear icon cache for a specific window or all windows
     * @param hwnd Window handle to clear from cache, or nullptr to clear entire cache
     */
    static void clearIconCache(HWND hwnd = nullptr);

    /**
     * @brief Get the handle of the foreground window
     * @return Handle to the foreground window
     */
    static HWND getForegroundWindow();

private:
    /**
     * @brief Log a Win32 API error with function name and error code
     * @param functionName Name of the function that failed
     */
    static void logWin32Error(const QString &functionName);

    /**
     * @brief Log a Win32 API error with function name and custom error code
     * @param functionName Name of the function that failed
     * @param errorCode The error code to log
     */
    static void logWin32Error(const QString &functionName, DWORD errorCode);
};

#endif // WIN32UTILS_H
