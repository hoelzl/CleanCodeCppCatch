#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include "Project.h"
#include <string>

enum class EmployeeType
{
    Regular,
    Houred,
    Commissioned
};

class Employee
{
private:
    int id;
    std::string name;
    EmployeeType type;
    double salary;// only for regular employees
    int overtime; // for regular employees or freelancers (houred)
    Project& project;

public:
    Employee(int id, std::string name, EmployeeType type, double salary, int overtime, Project& project);
    static double calculate_pay(EmployeeType employee_type);
    static std::string report_hours(EmployeeType employee_type);
    void print_report();
    void save_employee();
    double calculateRegularHours() const;
};


#endif//EMPLOYEE_EMPLOYEE_H
