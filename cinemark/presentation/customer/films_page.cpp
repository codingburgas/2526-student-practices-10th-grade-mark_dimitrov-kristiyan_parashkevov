#include "films_page.h"
#include "film_widget.h"
#include "film_paginator.h"
#include "seat_dialog.h"
#include "ticket_controller.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QMessageBox>

FilmsPage::FilmsPage(User user, QWidget* parent)
    : QWidget(parent)
    , user(user)
{
    QVBoxLayout* autoExpander = new QVBoxLayout(this);
    QScrollArea* scroll = new QScrollArea(this);
    autoExpander->addWidget(scroll);
    scroll->setWidgetResizable(true);
    QWidget* scrollWidget = new QWidget(scroll);

    QVBoxLayout* pageLayout = new QVBoxLayout(scrollWidget);

    FilmPaginator paginator;
    for (Film film = paginator.next(); !film.title.isNull(); film = paginator.next())
    {
        FilmWidget* widget = new FilmWidget(film);
        pageLayout->addWidget(widget);
        QObject::connect(widget, &FilmWidget::buyPressed, this, &FilmsPage::onBuyPressed);
    }
    pageLayout->addStretch(1);

    scroll->setWidget(scrollWidget);
}

void FilmsPage::onBuyPressed(Film film)
{
    SeatDialog seatDialog(this);
    int status = seatDialog.exec();
    if (status == QDialog::Rejected)
        return;

    int ticketNumber = TicketController::issueTicket(user, film, seatDialog.pickedSeat);
    if (ticketNumber == -1)
    {
        QMessageBox::critical(this, "Order Failed", "This seat has already been reserved.");
    }
    else
    {
        QMessageBox::information(this, "Order Successful", QString::asprintf("Your ticket is: %08d", ticketNumber));
    }
}
