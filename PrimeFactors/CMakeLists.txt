cmake_minimum_required (VERSION 3.8)
project(PrimeFactors)

set(CMAKE_CXX_STANDARD 98)

set(PRIME_FACTOR_SOURCES  "prime_factors.cpp" "prime_factors.h")
set(PRIME_FACTOR_MAIN "prime_factors_main.cpp")
set(PRIME_FACTOR_TEST "catch.hpp" "prime_factors_test.cpp")

add_executable (PrimeFactors ${PRIME_FACTOR_SOURCES} ${PRIME_FACTOR_MAIN})
add_executable(PrimeFactorsTest ${PRIME_FACTOR_SOURCES} ${PRIME_FACTOR_TEST})
