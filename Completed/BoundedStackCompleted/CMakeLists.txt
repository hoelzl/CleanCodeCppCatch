cmake_minimum_required (VERSION 3.8)
project(BoundedStackCompleted)

set(CMAKE_CXX_STANDARD 17)

set(stack_sources "simple_bounded_stack.h")
set(stack_test "stack_test.cpp")

add_executable(BoundedStackTest ${stack_sources} ${stack_test})
target_link_libraries(BoundedStackTest "Catch2WithMain")