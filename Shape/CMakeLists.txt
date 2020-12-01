# CMakeList.txt : CMake project for Shape 
#
cmake_minimum_required (VERSION 3.8)
project(Shape)

set(CMAKE_CXX_STANDARD 17)

set(SHAPE_SOURCES  "shape.h" "shape.cpp")
set(SHAPE_MAIN "shape_main.cpp")

# Add source to this project's executable.
add_executable (Shape ${SHAPE_SOURCES} ${SHAPE_MAIN})
