cmake_minimum_required(VERSION 3.26)
project(DisparoLunar)

set(CMAKE_CXX_STANDARD 17)

add_executable(DisparoLunar main.cpp)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(DisparoLunar PRIVATE box2d::box2d)