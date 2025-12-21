#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

#include <QLayout>
#include <QRect>
#include <QStyle>

/**
 * @brief Custom layout manager that arranges items in a flowing grid
 *
 * FlowLayout arranges items from left to right (or right to left) and wraps
 * to the next line when the current line runs out of space.
 */
class FlowLayout : public QLayout
{
public:
    /**
     * @brief Construct a new FlowLayout with a parent widget
     * @param parent Parent widget
     * @param margin Layout margin (-1 for default)
     * @param hSpacing Horizontal spacing between items (-1 for default)
     * @param vSpacing Vertical spacing between items (-1 for default)
     */
    explicit FlowLayout(QWidget *parent, int margin = -1, int hSpacing = -1,
                        int vSpacing = -1);

    /**
     * @brief Construct a new FlowLayout without a parent
     * @param margin Layout margin (-1 for default)
     * @param hSpacing Horizontal spacing between items (-1 for default)
     * @param vSpacing Vertical spacing between items (-1 for default)
     */
    explicit FlowLayout(int margin = -1, int hSpacing = -1, int vSpacing = -1);
    /**
     * @brief Destructor
     */
    ~FlowLayout();

    /**
     * @brief Add an item to the layout
     * @param item Pointer to the QLayoutItem to add
     */
    void addItem(QLayoutItem *item) override;
    /**
     * @brief Calculate the total width needed for a given height
     * @param height The height constraint
     * @return Required width
     */
    int totalWidthForHeight(int height) const;
    /**
     * @brief Get the horizontal spacing
     * @return Horizontal spacing in pixels
     */
    int horizontalSpacing() const;

    /**
     * @brief Get the vertical spacing
     * @return Vertical spacing in pixels
     */
    int verticalSpacing() const;
    /**
     * @brief Get the expanding directions
     * @return Orientation flags
     */
    Qt::Orientations expandingDirections() const override;
    /**
     * @brief Check if the layout has a height for width dependency
     * @return true
     */
    bool hasHeightForWidth() const override;

    /**
     * @brief Calculate the preferred height for a given width
     * @param width The width constraint
     * @return Required height
     */
    int heightForWidth(int) const override;
    /**
     * @brief Get the number of items in the layout
     * @return Item count
     */
    int count() const override;

    /**
     * @brief Get the item at a specific index
     * @param index Index of the item
     * @return Pointer to QLayoutItem or nullptr if index is invalid
     */
    QLayoutItem *itemAt(int index) const override;
    /**
     * @brief Get the minimum size required by the layout
     * @return Minimum size
     */
    QSize minimumSize() const override;

    /**
     * @brief Set the geometry of the layout
     * @param rect The bounding rectangle
     */
    void setGeometry(const QRect &rect) override;
    /**
     * @brief Get the preferred size of the layout
     * @return Size hint
     */
    QSize sizeHint() const override;

    /**
     * @brief Remove and return the item at a specific index
     * @param index Index of the item to remove
     * @return Pointer to the removed QLayoutItem or nullptr
     */
    QLayoutItem *takeAt(int index) override;

    /**
     * @brief Set Right-To-Left layout mode
     * @param enable true to enable RTL, false for LTR
     */
    void setRTL(bool enable) { m_isRTL = enable; }

private:
    /**
     * @brief Perform the layout calculation
     * @param rect The bounding rectangle
     * @param testOnly If true, only calculate size without moving items
     * @return The height required for the layout
     */
    int doLayout(const QRect &rect, bool testOnly) const;

    /**
     * @brief Calculate smart spacing based on style
     * @param pm Pixel metric to query
     * @return Spacing in pixels
     */
    int smartSpacing(QStyle::PixelMetric pm) const;

    /**
     * @brief Get the size of a layout item (handles testOnly mode)
     * @param item The layout item to measure
     * @param testOnly Whether we're in test mode
     * @return Size of the item
     */
    QSize getItemSize(QLayoutItem *item, bool testOnly) const;

    /**
     * @brief Check if we should wrap to the next column
     * @param currentY Current Y position
     * @param itemHeight Height of the item to add
     * @param effectiveRect The effective layout rectangle
     * @return true if we should wrap to next column
     */
    bool shouldWrapToNextColumn(int currentY, int itemHeight, const QRect &effectiveRect) const;

    /**
     * @brief Set the geometry of an item (handles RTL/LTR)
     * @param item The item to position
     * @param x X coordinate (left edge for LTR, right edge for RTL)
     * @param y Y coordinate
     * @param size Size of the item
     */
    void setItemGeometry(QLayoutItem *item, int x, int y, const QSize &size) const;

    QList<QLayoutItem *> m_itemList;
    int m_hSpace;
    int m_vSpace;
    bool m_isRTL = false;
};

#endif // FLOWLAYOUT_H
