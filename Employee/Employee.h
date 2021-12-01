
#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include "Project.h"
#include <iostream>
#include <string>

enum class EmployeeType
{
    Regular,
    Houred,
    Commissioned,
};

enum class SaveResult
{
    Successful,
    Failed,
};

class Employee
{
private:
    int id;
    std::string name;
    EmployeeType type;
    double salary;// only for regular employees
    int overtime; // for regular employees or freelancers (payed by the hour)
    const Project& project;

public:
    Employee(int id, std::string name, EmployeeType type, double salary,
             int overtime, const Project& project);

    int get_id() const;
    const std::string& get_name() const;
    const Project& get_project() const;

    double calculate_pay();
    std::string report_hours();
    void print_report(std::ostream& os = std::cout);
    SaveResult save_employee();
};


#endif// EMPLOYEE_EMPLOYEE_H
