cmake_minimum_required(VERSION 3.16)
project(EmployeeCompleted)

set(CMAKE_CXX_STANDARD 11)

add_executable(Employee main.cpp Project.cpp Project.h Employee.cpp Employee.h "PaymentCalculator.h" "HourReporter.h" "ReportPrinter.h" "ReportPrinter.cpp")
