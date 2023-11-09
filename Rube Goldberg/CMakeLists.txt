cmake_minimum_required(VERSION 3.26)
project(Rube_Goldberg)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rube_Goldberg main.cpp
        Shapes.h
)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(Rube_Goldberg PRIVATE box2d::box2d)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Rube_Goldberg PRIVATE sfml-system sfml-network sfml-graphics sfml-window)