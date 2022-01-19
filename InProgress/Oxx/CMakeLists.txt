cmake_minimum_required(VERSION 3.16)
project(Oxx)

set(CMAKE_CXX_STANDARD 23)

set(OxxSources
  "cli.cpp"
  "cli.hpp"
  "core.cpp"
  "core.hpp"
  "game.cpp"
  "game.hpp"
  "single_player_game.cpp"
  "single_player_game.hpp"
)

add_executable(Oxx "main.cpp" ${OxxSources})

add_executable(OxxTest "core_test.cpp" ${OxxSources})
target_link_libraries(OxxTest "Catch2WithMain")
