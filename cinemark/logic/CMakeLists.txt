qt_add_library(logic STATIC
    types.h
    testtablemodel.h
    testtablemodel.cpp
)

target_link_libraries(logic PUBLIC Qt::Core)

target_include_directories(logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
