cmake_minimum_required (VERSION 3.8)
project(Workshops)

set(CMAKE_CXX_STANDARD 17)

set(SALARIES_ORIGINAL_SOURCES  "salaries_original.h" "salaries_original.cpp")
set(SALARIES_ORIGINAL_MAIN "salaries_original_main.cpp")

add_executable (SalariesOriginal ${SALARIES_ORIGINAL_SOURCES} ${SALARIES_ORIGINAL_MAIN})
