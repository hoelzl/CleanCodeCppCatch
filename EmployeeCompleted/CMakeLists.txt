cmake_minimum_required(VERSION 3.16)
project(EmployeeCompleted)

set(CMAKE_CXX_STANDARD 11)

add_executable(Employee "EmployeeTestCompleted.cpp"
	Database.cpp 
	Database.h 
	Employee.cpp
	Employee.h
	Project.cpp
	Project.h
	ReportPrinter.cpp
	ReportPrinter.h
 "AugurDB.h" "AugurDatabase.h" "AugurDatabase.cpp")
