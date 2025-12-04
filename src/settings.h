#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QString>

class Settings
{
public:
    static Settings& instance();

    void load();

    // MainWindow
    int mainWindowRefreshIntervalMs;
    int mainWindowCloseRefreshDelayMs;
    int mainWindowInitialWidth;
    int mainWindowMinimumWidth;

    // Layout
    int layoutMargin;
    int layoutHSpacing;
    int layoutVSpacing;

    // WindowScanner
    int windowScannerMaxTitleLength;

    // WindowTile
    int tileWidth;
    int tileHeight;
    int tileIconSize;
    int tileContentMargin;
    int tileInternalSpacing;
    bool tileEnableShiftClickClose;

    // Display
    int targetDisplayIndex;

    // Shortcuts
    QString toggleVisibilityShortcut;
    int getToggleVisibilityKeyVk();

private:
    Settings();
    QSettings *m_settings;
    
    int qtKeyToVk(Qt::Key key);
};

#endif // SETTINGS_H
