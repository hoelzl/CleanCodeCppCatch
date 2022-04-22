cmake_minimum_required (VERSION 3.8)

set(CMAKE_SYSTEM_VERSION 8.1)

project ("CleanCodeCpp")

set(CMAKE_CXX_STANDARD 17)
IF(MSVC)
    SET(CMAKE_CXX_FLAGS "/EHsc")
ENDIF(MSVC)

option(ASAN_ENABLED "Build with AddressSanitizer" OFF)

add_subdirectory("Completed")
add_subdirectory("Examples")
add_subdirectory("External")
add_subdirectory("InProgress")
add_subdirectory("Workshops")
