#include "Employee.hpp"

#include <iostream>
#include <utility>

#include "EmployeeDao.hpp"
#include "ReportPrinter.hpp"

namespace employee_completed_simplified {

using namespace std::string_literals;

Employee::Employee(
    int id, std::string_view name, std::unique_ptr<PaymentScheme> payment_scheme,
    std::unique_ptr<EmployeeDao> dao, std::shared_ptr<const ReportPrinter> printer)
    : id{id}
    , name{name}
    , payment_scheme{std::move(payment_scheme)}
    , dao{std::move(dao)}
    , printer{std::move(printer)}
{}

double Employee::calculate_pay() const { return payment_scheme->calculate_pay(); }

int Employee::report_hours() const { return payment_scheme->report_hours(); }

void Employee::print_report() const { printer->print_report(*this); }

SaveResult Employee::save_employee() const { return dao->save(*this); }
} // namespace employee_completed_simplified