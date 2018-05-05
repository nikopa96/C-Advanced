cmake_minimum_required(VERSION 3.8)
project(Prax11)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp item.cpp item.h order.cpp order.h stock.cpp stock.h cart.cpp cart.h)
add_executable(Prax11 ${SOURCE_FILES})