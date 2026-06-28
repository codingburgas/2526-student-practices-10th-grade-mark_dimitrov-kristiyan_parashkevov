#include "ticket_query.h"
#include "database.h"
#include <QSqlQuery>

bool TicketQuery::isSeatReserved(Film film, int seatNumber)
{
    Database::ensureDefaultConnection();

    QSqlQuery query;
    query.prepare(
        "SELECT TOP 1 Id FROM Tickets "
        "WHERE FilmId = ? AND SeatNumber = ?");
    query.addBindValue(film.id);
    query.addBindValue(seatNumber);
    query.exec();
    return query.next();
}

int TicketQuery::generateTicket(Film film, int seatNumber, User user)
{
    Database::ensureDefaultConnection();

    QSqlQuery query;
    query.prepare(
        "INSERT INTO Tickets (FilmId, SeatNumber, UserId) VALUES (?, ?, ?);"
        "SELECT SCOPE_IDENTITY()");
    query.addBindValue(film.id);
    query.addBindValue(seatNumber);
    query.addBindValue(user.id);
    query.exec(); query.next();
    return query.value(0).toInt();
}
