cmake_minimum_required(VERSION 3.12)
project(Employee)

add_executable(EmployeeTest
	AugurDB.h 
	Employee.cpp 
	Employee.h 
	EmployeeTest.cpp 
	Project.cpp 
	Project.h
)
target_link_libraries(EmployeeTest "Catch2WithMain")
