#include "Employee.h"

#include <iostream>

namespace employee_workshop_simplified {

using namespace std::string_literals;

double Employee::calculate_pay() const
{
    switch (type) {
    case EmployeeType::regular: return salary + 60.0 * overtime;
    case EmployeeType::commissioned: return project.commissioned_pay;
    // We use overtime for the billed hours.
    case EmployeeType::houred: return 50.0 * overtime;
    }
    throw std::invalid_argument("Invalid employee type.");
}

int Employee::report_hours() const
{
    switch (type) {
    case EmployeeType::regular: return 40 + overtime;
    case EmployeeType::commissioned: return 40;
    // We use overtime for the billed hours.
    case EmployeeType::houred: return overtime;
    }
    throw std::invalid_argument("Invalid employee type.");
}

void Employee::print_report() const
{
    printer->print_report(*this);
}

SaveResult Employee::save_employee() const
{
    database->start_transaction();
    database->store_field("id"s, id);
    database->store_field("name"s, name);
    database->store_field("type"s, type);
    database->store_field("salary"s, salary);
    database->store_field("project"s, project.name);
    database->commit_transaction();
    return SaveResult::successful;
}
} // namespace employee_workshop_simplified