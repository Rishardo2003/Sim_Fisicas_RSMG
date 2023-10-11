cmake_minimum_required(VERSION 3.26)
project(polygonShape)

set(CMAKE_CXX_STANDARD 17)

add_executable(polygonShape main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(polygonShape PRIVATE box2d::box2d)