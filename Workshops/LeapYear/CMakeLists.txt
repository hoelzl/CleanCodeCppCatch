cmake_minimum_required(VERSION 3.12)
project(LeapYear)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeapYearTest main.cpp)
target_link_libraries(LeapYearTest "Catch2WithMain")
