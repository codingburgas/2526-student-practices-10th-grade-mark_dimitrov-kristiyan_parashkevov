#pragma once

#include "film.h"
#include "user.h"
#include <QWidget>

class FilmsPage : public QWidget
{
    Q_OBJECT

public:
    explicit FilmsPage(User user, QWidget* parent = nullptr);

public slots:
    void onBuyPressed(Film film);

private:
    User user;
};
