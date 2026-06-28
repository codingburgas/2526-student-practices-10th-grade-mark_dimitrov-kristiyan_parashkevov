#pragma once

#include <QDialog>

class SeatDialog : public QDialog
{
    Q_OBJECT

public:
    SeatDialog(QWidget* parent = nullptr);

    int pickedSeat;

public slots:
    void onSeatPicked(int seatNumber);
};
