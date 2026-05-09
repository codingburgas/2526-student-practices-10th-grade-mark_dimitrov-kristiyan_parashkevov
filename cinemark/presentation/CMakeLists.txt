find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(app WIN32 MACOSX_BUNDLE
    main.cpp
    main_window.h main_window.cpp
    film_editor.h film_editor.cpp
)

target_link_libraries(app PRIVATE business_logic data_access Qt::Widgets)
