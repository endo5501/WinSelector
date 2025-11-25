#ifndef CONFIG_H
#define CONFIG_H

#include "settings.h"

// WinSelector Configuration
// Values are now loaded from Settings.ini via Settings class

namespace WinSelectorConfig
{
    // MainWindow Configuration
    namespace MainWindow
    {
        inline int refreshIntervalMs() { return Settings::instance().mainWindowRefreshIntervalMs; }
        inline int closeRefreshDelayMs() { return Settings::instance().mainWindowCloseRefreshDelayMs; }
        inline int initialWidth() { return Settings::instance().mainWindowInitialWidth; }
        inline int minimumWidth() { return Settings::instance().mainWindowMinimumWidth; }
    }

    // Layout Configuration
    namespace Layout
    {
        inline int margin() { return Settings::instance().layoutMargin; }
        inline int hSpacing() { return Settings::instance().layoutHSpacing; }
        inline int vSpacing() { return Settings::instance().layoutVSpacing; }
    }

    // WindowScanner Configuration
    namespace WindowScanner
    {
        inline int maxTitleLength() { return Settings::instance().windowScannerMaxTitleLength; }
    }

    // WindowTile Configuration
    namespace WindowTile
    {
        inline int width() { return Settings::instance().tileWidth; }
        inline int height() { return Settings::instance().tileHeight; }
        inline int iconSize() { return Settings::instance().tileIconSize; }
        inline int contentMargin() { return Settings::instance().tileContentMargin; }
        inline int internalSpacing() { return Settings::instance().tileInternalSpacing; }
    }
}

#endif // CONFIG_H
