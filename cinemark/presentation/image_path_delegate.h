#pragma once

#include <QStyledItemDelegate>

class ImagePathDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const override;
};
