#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include "HourReporter.h"
#include "PaymentCalculator.h"
#include "Project.h"
#include "ReportPrinter.h"
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
    PaymentCalculator& payment_calculator;
    HourReporter& hour_reporter;
    ReportPrinter& report_printer;

public:
    Employee(int id, std::string name, EmployeeType type, double salary,
             int overtime, Project& project,
             PaymentCalculator& payment_calculator, HourReporter& hour_reporter,
             ReportPrinter& report_printer);
    std::string get_name() const;

    double calculate_pay() const;
    std::string report_hours() const;
    void print_report() const;
    void save_employee() const;
    double calculate_regular_hours() const;
};


#endif//EMPLOYEE_EMPLOYEE_H