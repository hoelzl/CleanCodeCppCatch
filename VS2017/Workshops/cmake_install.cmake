# Install script for directory: C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/Workshops

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/CleanCodeCpp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/DvdShop/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/Employee/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/EmployeeSimplified/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/FizzBuzz/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/LeapYear/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/LoadBalancer/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/OneShots/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/Point/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/PrimeFactors/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/SalariesOriginal/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/SalariesWorkshop/cmake_install.cmake")
  include("C:/Users/tc/Programming/Cpp/Courses/CleanCodeCppCatch/VS2017/Workshops/Stack/cmake_install.cmake")

endif()
