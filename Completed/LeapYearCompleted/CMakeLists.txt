cmake_minimum_required(VERSION 3.16)
project(LeapYearCompleted)

add_executable(LeapYearCompletedTest main.cpp)
target_link_libraries(LeapYearCompletedTest "Catch2WithMain")
