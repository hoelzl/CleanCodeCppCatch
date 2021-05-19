cmake_minimum_required (VERSION 3.8)
project(ClockTimer)

set(CMAKE_CXX_STANDARD 17)

set(CLOCK_TIMER_SOURCES  "clock_timer.cpp" "clock_timer.hpp")
set(CLOCK_TIMER_MAIN "clock_timer_main.cpp")
set(CLOCK_TIMER_TEST "catch.hpp" "clock_timer_test.cpp")

add_executable (ClockTimer ${CLOCK_TIMER_SOURCES} ${CLOCK_TIMER_MAIN})
add_executable(ClockTimerTest ${CLOCK_TIMER_SOURCES} ${CLOCK_TIMER_TEST})
