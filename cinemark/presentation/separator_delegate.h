#pragma once

#include <QAbstractItemDelegate>

class SeparatorDelegate : public QAbstractItemDelegate
{
public:
    using QAbstractItemDelegate::QAbstractItemDelegate;

    void paint(QPainter*, const QStyleOptionViewItem&, const QModelIndex&) const override;
    QSize sizeHint(const QStyleOptionViewItem&, const QModelIndex&) const override;
};
