cmake_minimum_required(VERSION 3.16)
project(Ox)

set(CMAKE_CXX_STANDARD 17)

set(ox_sources "core.h" "core.cpp" "game.h" "game.cpp")

add_executable(ox "main.cpp" ${ox_sources})
add_executable("ox-test" "test_main.cpp" "core_test.cpp" ${ox_sources})

