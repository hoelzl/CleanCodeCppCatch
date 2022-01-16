cmake_minimum_required (VERSION 3.8)
project(StackCompleted)

set(CMAKE_CXX_STANDARD 17)

set(stack_sources  "stack.cpp" "stack.h")
set(stack_main "stack_main.cpp")
set(stack_test "stack_test.cpp")

# Add source to this project's executable.
add_executable (StackCompleted ${stack_sources} ${stack_main})
add_executable(StackCompletedTest ${stack_sources} ${stack_test})
target_link_libraries(StackCompletedTest "Catch2WithMain")