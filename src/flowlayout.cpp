#include "flowlayout.h"
#include <QDebug>
#include <QWidget>

FlowLayout::FlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing)
    : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

FlowLayout::FlowLayout(int margin, int hSpacing, int vSpacing)
    : m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

FlowLayout::~FlowLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
    {
        delete item;
    }
}

void FlowLayout::addItem(QLayoutItem *item)
{
    m_itemList.append(item);
    invalidate();
}

int FlowLayout::totalWidthForHeight(int height) const
{
    // Use a dummy rect with very large width and specified height
    // This ensures all items can fit horizontally and only wrap vertically when needed
    // For RTL mode, we need a valid positive width for correct calculations
    return doLayout(QRect(0, 0, 10000, height), true);
}

int FlowLayout::horizontalSpacing() const
{
    if (m_hSpace >= 0)
    {
        return m_hSpace;
    }
    return smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
}

int FlowLayout::verticalSpacing() const
{
    if (m_vSpace >= 0)
    {
        return m_vSpace;
    }
    return smartSpacing(QStyle::PM_LayoutVerticalSpacing);
}

int FlowLayout::count() const
{
    return m_itemList.size();
}

QLayoutItem *FlowLayout::itemAt(int index) const
{
    return m_itemList.value(index);
}

QLayoutItem *FlowLayout::takeAt(int index)
{
    if (index >= 0 && index < m_itemList.size())
    {
        QLayoutItem *item = m_itemList.takeAt(index);
        invalidate();
        return item;
    }
    return nullptr;
}

Qt::Orientations FlowLayout::expandingDirections() const
{
    return {};
}

bool FlowLayout::hasHeightForWidth() const
{
    return false;
}

int FlowLayout::heightForWidth(int width) const
{
    return -1;
}

void FlowLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}

QSize FlowLayout::sizeHint() const
{
    return minimumSize();
}

QSize FlowLayout::minimumSize() const
{
    QSize size;
    for (const QLayoutItem *item : m_itemList)
    {
        size = size.expandedTo(item->minimumSize());
    }

    const QMargins margins = contentsMargins();
    size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
    return size;
}

QSize FlowLayout::getItemSize(QLayoutItem *item, bool testOnly) const
{
    // When testOnly=true (calculating width), use widget's sizeHint directly
    // because QWidgetItem::sizeHint() returns (0,0) for hidden widgets
    if (testOnly && item->widget())
    {
        return item->widget()->sizeHint();
    }
    return item->sizeHint();
}

bool FlowLayout::shouldWrapToNextColumn(int currentY, int itemHeight, const QRect &effectiveRect) const
{
    // Wrap if we're not at the top and adding this item would exceed the bottom
    return effectiveRect.height() > 0 &&
           currentY + itemHeight > effectiveRect.bottom() &&
           currentY > effectiveRect.y();
}

void FlowLayout::setItemGeometry(QLayoutItem *item, int x, int y, const QSize &size) const
{
    if (m_isRTL)
    {
        // For RTL, x represents the right edge, so subtract width
        item->setGeometry(QRect(QPoint(x - size.width(), y), size));
    }
    else
    {
        // For LTR, x represents the left edge
        item->setGeometry(QRect(QPoint(x, y), size));
    }
}

int FlowLayout::doLayout(const QRect &rect, bool testOnly) const
{
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);
    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);

    int x = m_isRTL ? effectiveRect.right() + 1 : effectiveRect.x();
    int y = effectiveRect.y();
    int columnWidth = 0;

    for (QLayoutItem *item : m_itemList)
    {
        QSize size = getItemSize(item, testOnly);

        // Check if we need to wrap to the next column
        if (shouldWrapToNextColumn(y, size.height(), effectiveRect))
        {
            // Move to next column
            x = m_isRTL ? x - columnWidth - horizontalSpacing()
                        : x + columnWidth + horizontalSpacing();
            y = effectiveRect.y();
            columnWidth = 0;
        }

        // Position the item if not in test mode
        if (!testOnly)
        {
            setItemGeometry(item, x, y, size);
        }

        // Update tracking variables
        columnWidth = qMax(columnWidth, size.width());
        y += size.height() + verticalSpacing();
    }

    // Calculate and return the total width used
    if (m_isRTL)
    {
        return (effectiveRect.right() + 1) - (x - columnWidth) + right + left;
    }
    return x + columnWidth + right + left - rect.x();
}

int FlowLayout::smartSpacing(QStyle::PixelMetric pm) const
{
    QObject *parent = this->parent();
    if (!parent)
    {
        return -1;
    }
    else if (parent->isWidgetType())
    {
        QWidget *pw = static_cast<QWidget *>(parent);
        return pw->style()->pixelMetric(pm, nullptr, pw);
    }
    else
    {
        return static_cast<QLayout *>(parent)->spacing();
    }
}
