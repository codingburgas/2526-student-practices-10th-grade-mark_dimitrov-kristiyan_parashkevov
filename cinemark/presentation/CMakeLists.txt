find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(app WIN32 MACOSX_BUNDLE
    filmsscreen.h
    filmsscreen.cpp
    main.cpp
    mainwindow.h mainwindow.cpp
)

target_link_libraries(app PRIVATE logic Qt::Widgets)
