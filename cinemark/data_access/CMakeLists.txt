find_package(Qt6 REQUIRED COMPONENTS Sql)

qt_add_library(data_access STATIC
    film_table_model.h film_table_model.cpp
)

target_link_libraries(data_access PUBLIC Qt::Sql)

target_include_directories(data_access PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
