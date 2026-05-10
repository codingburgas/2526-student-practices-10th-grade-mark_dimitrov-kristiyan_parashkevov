qt_add_executable(app WIN32 MACOSX_BUNDLE
    main.cpp
    main_window.h main_window.cpp
    film_editor.h film_editor.cpp
    film_table_view.h film_table_view.cpp
    image_path_delegate.h image_path_delegate.cpp
)

target_link_libraries(app PRIVATE business_logic data_access Qt::Widgets)
