#include "film_paginator.h"
#include "database.h"

FilmPaginator::FilmPaginator()
{
    Database::ensureDefaultConnection();
    query = QSqlQuery("SELECT * FROM Films");
    query.setForwardOnly(true);
}

Film FilmPaginator::next()
{
    if (!query.next())
        return Film();

    Film result;
    result.id = query.value(0).toInt();
    result.poster = query.value(1).toString();
    result.title = query.value(2).toString();
    result.genre = query.value(3).toString();
    return result;
}
