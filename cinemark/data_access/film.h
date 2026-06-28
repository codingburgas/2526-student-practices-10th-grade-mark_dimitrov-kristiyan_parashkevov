#pragma once
#include <QString>

struct ProjectionInfo
{
    QString date;
    int hall;
};

struct Film
{
    int id;
    QString poster;
    QString title;
    QString genre;
    ProjectionInfo projections;
};
