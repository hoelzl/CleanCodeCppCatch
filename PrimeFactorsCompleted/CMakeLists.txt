﻿cmake_minimum_required (VERSION 3.8)
project(PrimeFactorsCompleted)

set(CMAKE_CXX_STANDARD 98)

set(PRIME_FACTOR_SOURCES  "prime_factors.cpp" "prime_factors.h")
set(PRIME_FACTOR_MAIN "prime_factors_main.cpp")
set(PRIME_FACTOR_TEST "catch.hpp" "prime_factors_test.cpp")

add_executable (PrimeFactorsCompleted ${PRIME_FACTOR_SOURCES} ${PRIME_FACTOR_MAIN})
add_executable(PrimeFactorsCompletedTest ${PRIME_FACTOR_SOURCES} ${PRIME_FACTOR_TEST})
