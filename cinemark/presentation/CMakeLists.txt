qt_add_executable(admin WIN32 MACOSX_BUNDLE
    main.cpp main_window.h main_window.cpp
    film_editor.h film_editor.cpp
    film_table_view.h film_table_view.cpp
    image_path_delegate.h image_path_delegate.cpp
    separator_delegate.h separator_delegate.cpp
    database_connection_dialog.h database_connection_dialog.cpp
)

qt_add_executable(customer WIN32 MACOSX_BUNDLE
    main.cpp main_window.h customer/main_window.cpp
    customer/films_page.h customer/films_page.cpp
    customer/film_widget.h customer/film_widget.cpp
    customer/seat_dialog.h customer/seat_dialog.cpp
    customer/seat_widget.h customer/seat_widget.cpp
)

target_link_libraries(admin PRIVATE business_logic data_access Qt::Widgets)

target_link_libraries(customer PRIVATE business_logic data_access Qt::Widgets)
target_link_directories(customer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
