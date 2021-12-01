#include "Employee.h"
#include <iostream>
#include <utility>


Employee::Employee(int id, std::string name,
                   std::shared_ptr<const ReportPrinter> report_printer,
                   std::shared_ptr<Database> database)
    : id{id}, name{std::move(name)},
      report_printer{std::move(report_printer)}, database{std::move(database)}
{
}

int Employee::get_id() const
{
    return id;
}

const std::string& Employee::get_name() const
{
    return name;
}

void Employee::print_report() const
{
    if (report_printer) {
        report_printer->print_report(*this);
    }
}

SaveResult Employee::save_employee() const
{
    if (database) {
        return database->save_employee(*this);
    }
    return SaveResult::Failed;
}

RegularEmployee::RegularEmployee(
        int id, std::string name, double salary, int overtime,
        std::shared_ptr<const ReportPrinter> report_printer,
        std::shared_ptr<Database> database)
    : Employee{id, name, std::move(report_printer), std::move(database)},
      salary{salary}, overtime{overtime}
{
}

double RegularEmployee::get_salary() const
{
    return salary;
}

int RegularEmployee::get_overtime() const
{
    return overtime;
}

double RegularEmployee::calculate_pay() const
{
    return salary + 60.0 * overtime;
}

int RegularEmployee::report_hours() const
{
    return 40 + overtime;
}

CommissionedEmployee::CommissionedEmployee(
        int id, std::string name, const Project& project,
        std::shared_ptr<const ReportPrinter> report_printer,
        std::shared_ptr<Database> database)
    : Employee{id, name, std::move(report_printer), std::move(database)},
      project{project}
{
}

const Project& CommissionedEmployee::get_project() const
{
    return project;
}

double CommissionedEmployee::calculate_pay() const
{
    return project.get_commissioned_pay();
}

int CommissionedEmployee::report_hours() const
{
    return 40;
}

FreelanceEmployee::FreelanceEmployee(
        int id, std::string name, int billable_hours,
        std::shared_ptr<const ReportPrinter> report_printer,
        std::shared_ptr<Database> database)
    : Employee{id, name, std::move(report_printer), std::move(database)},
      billable_hours{billable_hours}
{
}

int FreelanceEmployee::get_billable_hours() const
{
    return billable_hours;
}

double FreelanceEmployee::calculate_pay() const
{
    return 50.0 * billable_hours;
}

int FreelanceEmployee::report_hours() const
{
    return billable_hours;
}
