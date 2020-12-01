# CMakeList.txt : CMake project for Point, 
#
cmake_minimum_required (VERSION 3.8)
project(PointCompleted)

set(CMAKE_CXX_STANDARD 11)

set(POINT_SOURCES "abstract_point.h" "concrete_point.h")
set(POINT_MAIN "point.cpp")
set(POINT_TEST "abstract_point_test.cpp" "concrete_point_test.cpp" "point_test_main.cpp")

add_executable (Point ${POINT_SOURCES} ${POINT_MAIN})
add_executable (PointTest ${POINT_SOURCES} ${POINT_TEST})