cmake_minimum_required (VERSION 3.8)
project(Workshops)

set(CMAKE_CXX_STANDARD 17)

set(SALARIES_COMPLETED_SOURCES  "salaries_completed.h" "salaries_completed.cpp")
set(SALARIES_COMPLETED_MAIN "salaries_completed_main.cpp")

add_executable (SalariesCompleted ${SALARIES_COMPLETED_SOURCES} ${SALARIES_COMPLETED_MAIN})
