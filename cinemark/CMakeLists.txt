cmake_minimum_required(VERSION 3.22)

project(cinemark LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

add_subdirectory(data_access)
add_subdirectory(logic)
add_subdirectory(presentation)
