cmake_minimum_required (VERSION 3.8)
project(CleanCode)

set(CMAKE_CXX_STANDARD 20)

set(CLEAN_CODE_SOURCES  "clean_code.h" "names.cpp" "complex_function.cpp" "complex_function.hpp" "complex_function_refactored.hpp" "names.hpp" "functions.cpp" "functions.hpp" "complex_function_refactored.cpp" "classes.hpp" "classes.cpp")
set(CLEAN_CODE_MAIN "clean_code.cpp")

add_executable (CleanCode ${CLEAN_CODE_SOURCES} ${CLEAN_CODE_MAIN})
target_link_libraries(CleanCode GSL)