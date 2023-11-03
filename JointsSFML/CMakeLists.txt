cmake_minimum_required(VERSION 3.26)
project(JointsSFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(JointsSFML main.cpp)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(JointsSFML PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

find_package(box2d CONFIG REQUIRED)
target_link_libraries(JointsSFML PRIVATE box2d::box2d)