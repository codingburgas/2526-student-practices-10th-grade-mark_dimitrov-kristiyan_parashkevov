qt_add_library(business_logic STATIC
    types.h
)

target_link_libraries(business_logic PUBLIC Qt::Core)

target_include_directories(business_logic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
