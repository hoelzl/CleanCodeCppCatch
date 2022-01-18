cmake_minimum_required(VERSION 3.16)
project(Employee)

set(CMAKE_CXX_STANDARD 20)

add_executable(EmployeeSimplifiedCompletedTest
	"AugurDB.hpp"
	"Employee.cpp"
	"Employee.hpp"
	"EmployeeTest.cpp"
	"Project.hpp"
	"PaymentScheme.hpp"
 "PaymentScheme.cpp")
target_link_libraries(EmployeeSimplifiedCompletedTest "Catch2WithMain")
