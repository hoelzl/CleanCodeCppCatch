cmake_minimum_required(VERSION 3.12)

# We don't want to fail for old cmake versions, since this would make
# auto-generation of VS solutions more difficult, but we only want to
# generate the targets for this file if we have a modately modern cmake.

if (${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 3.16)

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

endif (${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 3.16)
