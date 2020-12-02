cmake_minimum_required (VERSION 3.8)
project(LoadBalancerCompleted)

set(CMAKE_CXX_STANDARD 17)

set(LOAD_BALANCER_SOURCES
    "controller.cpp" "controller.h"
    "load_balancer.cpp" "load_balancer.h" "resource.h")
set(LOAD_BALANCER_MAIN "load_balancer_main.cpp")

add_executable (LoadBalancer ${LOAD_BALANCER_SOURCES} ${LOAD_BALANCER_MAIN})

