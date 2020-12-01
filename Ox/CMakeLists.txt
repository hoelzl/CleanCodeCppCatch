cmake_minimum_required(VERSION 3.16)
project(Ox)

set(CMAKE_CXX_STANDARD 17)

add_executable(ox main.cpp core.h core.cpp)
add_executable("ox-test" test_main.cpp core.h core.cpp core_test.cpp)

