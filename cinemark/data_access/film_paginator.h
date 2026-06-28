#pragma once

#include "film.h"
#include <QSqlQuery>

class FilmPaginator
{
public:
    FilmPaginator();

    Film next();

private:
    QSqlQuery query;
};
