cmake_minimum_required(VERSION 3.8)
project(Prax14)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp ThreadPool.cpp ThreadPool.h)
add_executable(Prax14 ${SOURCE_FILES})