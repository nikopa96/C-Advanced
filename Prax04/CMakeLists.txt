cmake_minimum_required(VERSION 3.8)
project(Prax04)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)

# Remove 'lib' prefix for shared libraries on Windows
if (WIN32)
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif ()

add_subdirectory(3rd-party/googletest)

find_library(gtest REQUIRED)
include_directories(${gtest_SOURCE_DIR}/include)

add_executable(Prax04 src/main.cpp src/pointers.hpp src/pointers.cpp src/test.cpp)
target_link_libraries(Prax04 gtest)