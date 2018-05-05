cmake_minimum_required(VERSION 3.8)
project(Prax13)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)

set(SOURCE_FILES main.cpp Room.cpp Room.h Player.cpp Player.h)
add_executable(Prax13 ${SOURCE_FILES})
target_link_libraries(Prax13 Threads::Threads)
