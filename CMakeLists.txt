project(e2node)

cmake_minimum_required(VERSION 3.10)

if (TESTING)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-O0 -ggdb -fprofile-arcs -ftest-coverage")
endif()

include_directories(include)

add_subdirectory(src)
add_subdirectory(simulator)
add_subdirectory(test)
