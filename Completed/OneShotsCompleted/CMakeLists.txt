cmake_minimum_required (VERSION 3.8)
project(OneShotsCompleted)


add_executable (OneShotsCompletedTest "argument_passing.cpp")
target_link_libraries(OneShotsCompletedTest "Catch2WithMain" "GSL")
