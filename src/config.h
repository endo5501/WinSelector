#ifndef CONFIG_H
#define CONFIG_H

// WinSelector Configuration Constants
// This file centralizes all magic numbers and configuration values

namespace WinSelectorConfig
{
    // MainWindow Configuration
    namespace MainWindow
    {
        // Timer intervals (milliseconds)
        constexpr int REFRESH_INTERVAL_MS = 2000;        // Window list refresh interval
        constexpr int CLOSE_REFRESH_DELAY_MS = 500;      // Delay after closing a window

        // Window dimensions
        constexpr int INITIAL_WIDTH = 300;               // Initial window width
        constexpr int MINIMUM_WIDTH = 300;               // Minimum window width
    }

    // Layout Configuration
    namespace Layout
    {
        constexpr int MARGIN = 2;                        // Layout margin
        constexpr int HSPACING = 2;                      // Horizontal spacing
        constexpr int VSPACING = 2;                      // Vertical spacing
    }

    // WindowScanner Configuration
    namespace WindowScanner
    {
        constexpr int MAX_TITLE_LENGTH = 256;            // Maximum window title length
    }
}

#endif // CONFIG_H
