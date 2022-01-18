cmake_minimum_required(VERSION 3.16)
project(Employee)

add_executable(EmployeeSimplifiedTest
	AugurDB.h 
	Employee.cpp 
	Employee.h 
	EmployeeTest.cpp 
	 
	Project.h
)
target_link_libraries(EmployeeSimplifiedTest "Catch2WithMain")
