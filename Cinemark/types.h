#pragma once

#include <string>

struct ProjectionInfo
{
    std::string date;
    int hall;
    std::string cinema;
};

struct Film
{
    std::string title;
    int yearReleased;
    std::string length;
    ProjectionInfo* projections;
    std::string genre;
};
