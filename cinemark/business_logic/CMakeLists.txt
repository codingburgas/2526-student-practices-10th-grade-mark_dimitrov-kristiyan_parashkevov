qt_add_library(business_logic STATIC
    ticket_controller.h ticket_controller.cpp
    user_controller.h user_controller.cpp
)

target_link_libraries(business_logic PUBLIC data_access Qt::Core)

target_include_directories(business_logic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
