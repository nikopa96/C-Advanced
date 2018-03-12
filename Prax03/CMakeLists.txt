cmake_minimum_required(VERSION 3.8)
project(Prax03)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -fno-elide-constructors)
include_directories(src)

set(SOURCE_FILES src/main.cpp src/complexnumber.h src/complexnumber.cpp)
add_executable(Prax03 ${SOURCE_FILES})
