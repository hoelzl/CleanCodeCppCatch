#include "Employee.h"
#include <iostream>
#include <utility>

using namespace std::string_literals;

Employee::Employee(int id, std::string name, EmployeeType type, double salary,
                   int overtime, const Project& project)
    : id{id}, name{std::move(name)}, type{type}, salary{salary},
      overtime{overtime}, project{project}
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

const Project& Employee::get_project() const
{
    return project;
}

double Employee::calculate_pay()
{
    switch (type) {
        case EmployeeType::Regular: return salary + 60.0 * overtime;
        case EmployeeType::Commissioned: return project.get_commissioned_pay();
        // We use overtime for the total hours worked.
        case EmployeeType::Houred: return 50.0 * overtime;
        default: throw std::invalid_argument("Invalid employee type.");
    }
}

std::string Employee::report_hours()
{
    switch (type) {
        case EmployeeType::Regular:
            return std::to_string(40 + overtime) + " hours"s;
        case EmployeeType::Commissioned: return "40 hours"s;
        // We use overtime for the total hours worked.
        case EmployeeType::Houred: return std::to_string(overtime) + " hours"s;
        default: throw std::invalid_argument("Invalid employee type.");
    }
}

void Employee::print_report(std::ostream& os /* = std::cout */)
{
    os << name << " worked " << report_hours() << ".\n";
}

SaveResult Employee::save_employee()
{
    return SaveResult::Successful;
}
