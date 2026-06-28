#pragma once

#include "film.h"
#include <QWidget>

class FilmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilmWidget(Film film, QWidget* parent = nullptr);

signals:
    void buyPressed(Film flm);

private:
    Film film;
};
