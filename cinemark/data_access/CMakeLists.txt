qt_add_library(data_access STATIC
    database.h
    database.cpp
)

target_link_libraries(data_access PUBLIC Qt::Core)

target_include_directories(data_access PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
