#include "seat_dialog.h"
#include "seat_widget.h"
#include <QGridLayout>

SeatDialog::SeatDialog(QWidget* parent)
    : QDialog(parent)
{
    QGridLayout* seats = new QGridLayout(this);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            auto* seatWidget = new SeatWidget(i * 10 + j + 1);
            seats->addWidget(seatWidget, i, j);
            QObject::connect(seatWidget, &SeatWidget::seatPicked, this, &SeatDialog::onSeatPicked);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        seats->setRowMinimumHeight(i, 30);
        seats->setColumnMinimumWidth(i, 30);
    }
}

void SeatDialog::onSeatPicked(int seatNumber)
{
    pickedSeat = seatNumber;
    accept();
}
