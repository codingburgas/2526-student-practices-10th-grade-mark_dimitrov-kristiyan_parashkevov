qt_add_library(data_access STATIC
    db_connection_parameters.h
    film_table_model.h film_table_model.cpp
    film_paginator.h film_paginator.cpp
    film.h user.h ticket.h
    database.h database.cpp
    ticket_query.h ticket_query.cpp
    user_query.h user_query.cpp
)

target_link_libraries(data_access PUBLIC Qt::Sql)

target_include_directories(data_access INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
