#pragma once

#include "user.h"
#include "film.h"

class TicketController
{
public:
    static int issueTicket(User user, Film film, int seatNumber);
};
