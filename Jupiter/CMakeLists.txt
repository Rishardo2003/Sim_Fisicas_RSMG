cmake_minimum_required(VERSION 3.26)
project(Jupiter)

set(CMAKE_CXX_STANDARD 17)

add_executable(Jupiter main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(Jupiter PRIVATE box2d::box2d)