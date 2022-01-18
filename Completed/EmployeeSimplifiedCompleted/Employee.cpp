#include "Employee.hpp"

#include <iostream>
#include <utility>

namespace employee_completed_simplified {

using namespace std::string_literals;

Employee::Employee(
    int id, std::string_view name, std::unique_ptr<PaymentScheme> payment_scheme,
    std::shared_ptr<AugurDb> database)
    : id{id}
    , name{name}
    , payment_scheme{std::move(payment_scheme)}
    , database{std::move(database)}
{}

double Employee::calculate_pay() const { return payment_scheme->calculate_pay(); }

int Employee::report_hours() const { return payment_scheme->report_hours(); }

void Employee::print_report(std::ostream& os /* = std::cout */) const
{
    os << name << " worked " << report_hours() << " hours.\n";
}

SaveResult Employee::save_employee() const
{
    database->start_transaction();
    database->store_field("id"s, id);
    database->store_field("name"s, name);
    payment_scheme->save_fields(database);
    database->commit_transaction();
    return SaveResult::successful;
}
} // namespace employee_completed_simplified