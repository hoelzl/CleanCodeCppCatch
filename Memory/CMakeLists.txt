# CMakeList.txt : CMake project for Point, 
#
cmake_minimum_required (VERSION 3.8)
project(Memory)

set(CMAKE_CXX_STANDARD 11)

set(MEMROY_SOURCES "main.cpp")

add_executable (Memory ${MEMROY_SOURCES})
