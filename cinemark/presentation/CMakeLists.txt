find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(app WIN32 MACOSX_BUNDLE
    films_screen.h
    films_screen.cpp
    main.cpp
    main_window.h
    main_window.cpp
)

target_link_libraries(app PRIVATE business_logic Qt::Widgets)
