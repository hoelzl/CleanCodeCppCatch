#include "Employee.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace employee_completed {
Employee::Employee(
    int id, std::string name, std::unique_ptr<const PaymentScheme> payment_scheme,
    std::shared_ptr<const ReportPrinter> report_printer,
    std::shared_ptr<Database> database)
    : id{id}
    , name{std::move(name)}
    , payment_scheme{std::move(payment_scheme)}
    , report_printer{std::move(report_printer)}
    , database{std::move(database)}
{}

int Employee::get_id() const { return id; }

const std::string& Employee::get_name() const { return name; }

const PaymentScheme& Employee::get_payment_scheme() const
{
    if (payment_scheme) {
        return *payment_scheme;
    }
    throw std::logic_error("No payment scheme?");
}

double Employee::calculate_pay() const
{
    if (payment_scheme) {
        return payment_scheme->calculate_pay(*this);
    }
    throw std::logic_error("No payment scheme?");
}

int Employee::report_hours() const
{
    if (payment_scheme) {
        return payment_scheme->get_total_hours();
    }
    throw std::logic_error("No payment scheme?");
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
    return SaveResult::failed;
}
} // namespace employee_completed