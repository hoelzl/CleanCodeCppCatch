cmake_minimum_required (VERSION 3.8)
project(CleanCode)

set(CMAKE_CXX_STANDARD 17)

set(CLEAN_CODE_SOURCES  "iterators.hpp" "iterators.cpp")
set(CLEAN_CODE_MAIN "iterators_main.cpp")

add_executable (Iterators ${CLEAN_CODE_SOURCES} ${CLEAN_CODE_MAIN})
