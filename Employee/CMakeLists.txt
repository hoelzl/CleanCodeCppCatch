cmake_minimum_required(VERSION 3.16)
project(Employee)

set(CMAKE_CXX_STANDARD 17)

add_executable(Employee
	AugurDB.h 
	Employee.cpp 
	Employee.h 
	EmployeeTest.cpp 
	Project.cpp 
	Project.h
)
