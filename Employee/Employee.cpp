//
// Created by tc on 08/07/2020.
//

#include "Employee.h"
#include <iostream>
#include <utility>


Employee::Employee(int id, std::string name, EmployeeType type, double salary, int overtime, Project& project)
    : id(id), name(std::move(name)), type(type), salary(salary), overtime(overtime), project(project)
{
}
double Employee::calculate_pay(EmployeeType employee_type)
{
    return 1000.0;
}

std::string Employee::report_hours(EmployeeType employee_type)
{
    return "40 hours";
}

void Employee::print_report()
{
    std::cout << "Report for " + name;
}

void Employee::save_employee()
{
}

double Employee::calculateRegularHours() const
{
    return 40.0 + overtime;
}
