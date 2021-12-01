#include "Employee.h"
#include <iostream>
#include <utility>

using namespace std::string_literals;

Employee::Employee(int id, std::string name, EmployeeType type, double salary,
                   int overtime, const Project& project,
                   std::shared_ptr<AugurDB> database)
    : id{id}, name{std::move(name)}, type{type}, salary{salary},
      overtime{overtime}, project{project}, database{std::move(database)}
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

double Employee::calculate_pay() const
{
    switch (type) {
        case EmployeeType::Regular: return salary + 60.0 * overtime;
        case EmployeeType::Commissioned: return project.get_commissioned_pay();
        // We use overtime for the billed hours.
        case EmployeeType::Houred: return 50.0 * overtime;
        default: throw std::invalid_argument("Invalid employee type.");
    }
}

int Employee::report_hours() const
{
    switch (type) {
        case EmployeeType::Regular: return 40 + overtime;
        case EmployeeType::Commissioned: return 40;
        // We use overtime for the billed hours.
        case EmployeeType::Houred: return overtime;
        default: throw std::invalid_argument("Invalid employee type.");
    }
}

void Employee::print_report(std::ostream& os /* = std::cout */) const
{
    os << name << " worked " << report_hours() << " hours.\n";
}

SaveResult Employee::save_employee() const
{
    database->start_transaction();
    database->store_field("id"s, id);
    database->store_field("name"s, name);
    database->store_field("type"s, type);
    database->store_field("salary"s, salary);
    database->store_field("project"s, project.get_name());
    database->commit_transaction();
    return SaveResult::Successful;
}
