#include "Employee.h"
#include <iostream>
#include <utility>


Employee::Employee(int id, std::string name, EmployeeType type, double salary,
                   int overtime, Project& project,
                   PaymentCalculator& payment_calculator,
                   HourReporter& hour_reporter, ReportPrinter& report_printer)
    : id(id), name(std::move(name)), type(type), salary(salary),
      overtime(overtime),
      project(project), payment_calculator{payment_calculator},
      hour_reporter{hour_reporter}, report_printer{report_printer}
{
}

std::string Employee::get_name() const
{
    return name;
}

double Employee::calculate_pay() const
{
    return payment_calculator.calculate_pay(*this);
}

std::string Employee::report_hours() const
{
    return hour_reporter.report_hours(*this);
}

void Employee::print_report() const
{
    std::cout << "Report for " + name;
}

void Employee::save_employee() const
{
}

double Employee::calculate_regular_hours() const
{
    return 40.0 + overtime;
}
