#pragma once

#include "film.h"
#include "user.h"

class TicketQuery
{
public:
    static int generateTicket(Film film, int seatNumber, User user);
    static bool isSeatReserved(Film film, int seatNumber);
};
