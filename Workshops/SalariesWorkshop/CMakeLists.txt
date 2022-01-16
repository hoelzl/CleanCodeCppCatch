cmake_minimum_required (VERSION 3.8)
project(Workshops)

set(CMAKE_CXX_STANDARD 17)

set(SALARIES_SOURCES  "salaries_workshop.h" "salaries_workshop.cpp")
set(SALARIES_MAIN "salaries_workshop_main.cpp")

add_executable (SalariesWorkshop ${SALARIES_SOURCES} ${SALARIES_MAIN})
