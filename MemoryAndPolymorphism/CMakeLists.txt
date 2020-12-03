cmake_minimum_required (VERSION 3.12)
project(MemoryAndPolymorphism)

set(CMAKE_CXX_STANDARD 20)

set(MEMROY_SOURCES "memory_main.cpp" "print_memory_layout.cpp" "print_memory_layout.h" "polymorphic_array.h")

add_executable (Memory ${MEMROY_SOURCES})
add_executable (Polymorphism "polymorphism_main.cpp" "animal.h" "dog.h" "cat.h")
