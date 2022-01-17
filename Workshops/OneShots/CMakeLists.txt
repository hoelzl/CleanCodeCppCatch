cmake_minimum_required (VERSION 3.8)
project(OneShots)


add_executable (OneShotsTest "argument_passing.cpp")
target_link_libraries(OneShotsTest "Catch2WithMain" "GSL")
