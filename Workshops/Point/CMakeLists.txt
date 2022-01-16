# CMakeList.txt : CMake project for Point, 
#
cmake_minimum_required (VERSION 3.8)
project(Point)

set(CMAKE_CXX_STANDARD 11)

set(POINT_SOURCES "encapsulated_point.h" "raw_point.h")
set(POINT_MAIN "point.cpp")
set(POINT_TEST "encapsulated_point_test.cpp" "raw_point_test.cpp" "point_test_main.cpp")

add_executable (Point ${POINT_SOURCES} ${POINT_MAIN})
add_executable (PointTest ${POINT_SOURCES} ${POINT_TEST})
target_link_libraries(PointTest "Catch2WithMain")
