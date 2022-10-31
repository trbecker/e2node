project(e2node)

cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_FLAGS "-O0 -ggdb")

include_directories(include)

add_subdirectory(src)
add_subdirectory(simulator)
add_subdirectory(test)
