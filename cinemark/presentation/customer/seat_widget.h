#pragma once

#include <QWidget>

class SeatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SeatWidget(int seatNumber, QWidget* parent = nullptr);

signals:
    void seatPicked(int seatNumber);

protected:
    virtual void mouseReleaseEvent(QMouseEvent*) override;

private:
    int seatNumber;
};
