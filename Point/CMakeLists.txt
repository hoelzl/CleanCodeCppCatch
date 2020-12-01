# CMakeList.txt : CMake project for Point, 
#
cmake_minimum_required (VERSION 3.8)
project(Point)

set(CMAKE_CXX_STANDARD 11)

set(POINT_SOURCES  "concrete_point.h" "abstract_point.h")
set(POINT_MAIN "point.cpp")

add_executable (Point ${POINT_SOURCES} ${POINT_MAIN})
