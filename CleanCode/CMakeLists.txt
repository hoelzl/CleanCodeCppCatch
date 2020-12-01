cmake_minimum_required (VERSION 3.8)
project(CleanCode)

set(CMAKE_CXX_STANDARD 98)

set(CLEAN_CODE_SOURCES  "clean_code.h" "names.cpp" "complex_function.cpp" "complex_function.h")
set(CLEAN_CODE_MAIN "clean_code.cpp")

add_executable (CleanCode ${CLEAN_CODE_SOURCES} ${CLEAN_CODE_MAIN})
