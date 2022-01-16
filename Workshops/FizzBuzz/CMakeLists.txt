cmake_minimum_required (VERSION 3.8)
project(FizzBuzz)

set(CMAKE_CXX_STANDARD 11)

set(FIZZ_BUZZ_SOURCES  "fizz_buzz.cpp" "fizz_buzz.h")
set(FIZZ_BUZZ_MAIN "fizz_buzz_main.cpp")
set(FIZZ_BUZZ_TEST "fizz_buzz_test.cpp")

add_executable (FizzBuzz ${FIZZ_BUZZ_SOURCES} ${FIZZ_BUZZ_MAIN})
add_executable(FizzBuzzTest ${FIZZ_BUZZ_SOURCES} ${FIZZ_BUZZ_TEST})
target_link_libraries(FizzBuzzTest "Catch2WithMain")
