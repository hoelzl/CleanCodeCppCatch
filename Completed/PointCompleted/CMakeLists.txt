﻿# CMakeList.txt : CMake project for Point, 
#
cmake_minimum_required (VERSION 3.8)
project(PointCompleted)

set(CMAKE_CXX_STANDARD 11)

set(POINT_SOURCES "encapsulated_point.h" "raw_point.h")
set(POINT_MAIN "point_main.cpp")
set(POINT_TEST "encapsulated_point_test.cpp" "raw_point_test.cpp" )

add_executable (PointCompleted ${POINT_SOURCES} ${POINT_MAIN})
add_executable (PointCompletedTest ${POINT_SOURCES} ${POINT_TEST})
target_link_libraries(PointCompletedTest "Catch2WithMain")