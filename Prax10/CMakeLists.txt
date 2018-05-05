cmake_minimum_required(VERSION 3.8)
project(Prax10)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp item.cpp item.h order.cpp order.h stock.cpp stock.h)
add_executable(Prax10 ${SOURCE_FILES})