#include "seat_widget.h"
#include <QVBoxLayout>
#include <QLabel>

SeatWidget::SeatWidget(int seatNumber, QWidget* parent)
    : QWidget(parent)
    , seatNumber(seatNumber)
{
    auto* center = new QVBoxLayout(this);
    center->addWidget(new QLabel(QString::number(seatNumber), this), 0, Qt::AlignCenter);
}

void SeatWidget::mouseReleaseEvent(QMouseEvent* event)
{
    emit seatPicked(seatNumber);

    QWidget::mouseReleaseEvent(event);
}
