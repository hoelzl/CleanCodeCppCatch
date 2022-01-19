
#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <memory>
#include <string>

#include "AugurDB.hpp"
#include "PaymentScheme.hpp"

namespace employee_completed_simplified {

enum class SaveResult;
struct EmployeeDao;
struct ReportPrinter;

struct Employee
{
    Employee(
        int id, std::string_view name, std::unique_ptr<PaymentScheme> payment_scheme,
        std::unique_ptr<EmployeeDao> dao, std::shared_ptr<const ReportPrinter> printer);

    int id{};
    std::string name{};
    std::unique_ptr<PaymentScheme> payment_scheme{};
    std::unique_ptr<EmployeeDao> dao;
    std::shared_ptr<const ReportPrinter> printer;

    [[nodiscard]] double calculate_pay() const;
    [[nodiscard]] int report_hours() const;
    void print_report() const;
    [[nodiscard]] SaveResult save_employee() const; // save to database
};
} // namespace employee_completed_simplified
#endif // EMPLOYEE_EMPLOYEE_H
