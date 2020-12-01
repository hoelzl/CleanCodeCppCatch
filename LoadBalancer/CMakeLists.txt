cmake_minimum_required (VERSION 3.8)
project(LoadBalancer)

set(CMAKE_CXX_STANDARD 11)

set(LOAD_BALANCER_SOURCES
    "controller.cpp" "controller.h"
    "load_balancer.cpp" "load_balancer.h")
set(LOAD_BALANCER_MAIN "load_balancer_main.cpp")

add_executable (LoadBalancer ${LOAD_BALANCER_SOURCES} ${LOAD_BALANCER_MAIN})

