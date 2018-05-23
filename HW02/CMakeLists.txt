cmake_minimum_required(VERSION 3.8)
project(HW02)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)

set(SOURCE_FILES main.cpp Player.cpp Player.h Tile.cpp Tile.h Board.cpp Board.h Card.cpp Card.h)
add_executable(HW02 ${SOURCE_FILES})
target_link_libraries(HW02 Threads::Threads)
