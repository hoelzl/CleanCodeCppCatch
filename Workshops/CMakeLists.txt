cmake_minimum_required (VERSION 3.8)
project(Workshops)

set(CMAKE_CXX_STANDARD 17)

set(SALARIES_ORIGINAL_SOURCES  "salaries_original.h" "salaries_original.cpp")
set(SALARIES_ORIGINAL_MAIN "salaries_original_main.cpp")

add_executable (SalariesOriginal ${SALARIES_ORIGINAL_SOURCES} ${SALARIES_ORIGINAL_MAIN})

set(SALARIES_SOURCES  "salaries_workshop.h" "salaries_workshop.cpp")
set(SALARIES_MAIN "salaries_workshop_main.cpp")

add_executable (SalariesWorkshop ${SALARIES_SOURCES} ${SALARIES_MAIN})

set(SALARIES_COMPLETED_SOURCES  "salaries_completed.h" "salaries_completed.cpp")
set(SALARIES_COMPLETED_MAIN "salaries_completed_main.cpp")

add_executable (SalariesCompleted ${SALARIES_COMPLETED_SOURCES} ${SALARIES_COMPLETED_MAIN})
