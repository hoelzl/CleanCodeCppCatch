cmake_minimum_required (VERSION 3.12)
project(MemoryAndPolymorphism)

set(CMAKE_CXX_STANDARD 20)
set(MEMORY_SOURCES
        "memory_main.cpp"
        "print_memory_layout.cpp"
        "print_memory_layout.h"
        "polymorphic_array.h")

add_executable (Simple "simple.cpp")
add_executable (Memory ${MEMORY_SOURCES})
target_link_libraries(Memory "GSL")
add_executable (Polymorphism "polymorphism_main.cpp" "animal.h" "dog.h" "cat.h")
add_executable (CopyMove "copy_move_main.cpp" "animal.h" "dog.h" "cat.h")
