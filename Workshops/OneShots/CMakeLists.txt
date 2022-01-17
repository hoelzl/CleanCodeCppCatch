cmake_minimum_required (VERSION 3.8)
project(OneShots)

add_executable (OneShotsTest "argument_passing.cpp" "ownership_1.cpp")
target_link_libraries(OneShotsTest "Catch2WithMain" "GSL")

if(ASAN_ENABLED)
  if(MSVC)
    target_compile_options(OneShotsTest PUBLIC /fsanitize=address)

  else()
    target_compile_options(OneShotsTest PUBLIC -fsanitize=address)
    target_link_options(OneShotsTest PUBLIC -fsanitize=address)
  endif()
endif()
