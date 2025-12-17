#ifndef WINDOWTILE_H
#define WINDOWTILE_H

#include "windowscanner.h"
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>

/**
 * @brief Widget representing a single window tile
 *
 * Displays the window icon and title, and handles user interaction.
 */
class WindowTile : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Construct a new WindowTile
     * @param info Window information
     * @param parent Parent widget
     */
    explicit WindowTile(const WindowInfo &info, QWidget *parent = nullptr);

    /**
     * @brief Get the window information
     * @return WindowInfo object
     */
    WindowInfo getInfo() const { return m_info; }

    /**
     * @brief Set the window information
     * @param info New window information
     */
    void setInfo(const WindowInfo &info);

    /**
     * @brief Set the active state of the tile
     * @param active true if active, false otherwise
     */
    void setActive(bool active);

    /**
     * @brief Get the preferred size of the tile
     * @return Size hint
     */
    QSize sizeHint() const override;

    /**
     * @brief Enable or disable shift+click to close window
     * @param enabled true to enable, false to disable
     */
    void setEnableShiftClickClose(bool enabled);

    // Configuration is now handled by Settings class

signals:
    /**
     * @brief Signal emitted when the tile is activated (clicked)
     * @param hwnd Handle of the associated window
     */
    void activated(HWND hwnd);

    /**
     * @brief Signal emitted when the window is closed
     * @param hwnd Handle of the associated window
     */
    void closed(HWND hwnd);

    /**
     * @brief Signal emitted when user requests to launch a new instance
     * @param processPath Full path to the executable to launch
     */
    void launchRequested(const QString &processPath);

protected:
    /**
     * @brief Handle mouse press events
     * @param event Mouse event
     */
    void mousePressEvent(QMouseEvent *event) override;

private:
    WindowInfo m_info;
    bool m_isActive = false;
    bool m_enableShiftClickClose = false;
    QLabel *m_iconLabel;
    QLabel *m_titleLabel;

    void setupUi();

    /**
     * @brief Setup the style of the tile
     */
    void setupStyle();
};

#endif // WINDOWTILE_H
