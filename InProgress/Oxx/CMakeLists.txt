cmake_minimum_required(VERSION 3.16)
project(Ox)

set(OxSources "core.hpp" "core.cpp" "game.hpp" "game.cpp")

add_executable(Ox "main.cpp" ${OxSources})

add_executable(OxTest "core_test.cpp" ${OxSources})
target_link_libraries(OxTest "Catch2WithMain")
