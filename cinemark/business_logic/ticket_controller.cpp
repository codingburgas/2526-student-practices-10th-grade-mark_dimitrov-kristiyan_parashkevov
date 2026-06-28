#include "ticket_controller.h"
#include "ticket_query.h"

int TicketController::issueTicket(User user, Film film, int seatNumber)
{
    if (TicketQuery::isSeatReserved(film, seatNumber))
        return -1;

    return TicketQuery::generateTicket(film, seatNumber, user);
}
