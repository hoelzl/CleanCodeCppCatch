
#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <iostream>
#include <memory>
#include <string>

#include "AugurDB.hpp"
#include "PaymentScheme.hpp"
#include "Project.hpp"

namespace employee_completed_simplified {

enum class EmployeeType;

enum class SaveResult
{
    successful,
    failed,
};

struct Employee
{
    Employee(
        int id, std::string_view name, std::unique_ptr<PaymentScheme> payment_scheme,
        std::shared_ptr<AugurDb> database);

    int id{};
    std::string name{};
    std::unique_ptr<PaymentScheme> payment_scheme{};
    std::shared_ptr<AugurDb> database{};

    [[nodiscard]] double calculate_pay() const;
    [[nodiscard]] int report_hours() const;
    void print_report(std::ostream& os = std::cout) const;
    [[nodiscard]] SaveResult save_employee() const; // save to database
};
} // namespace employee_completed_simplified
#endif // EMPLOYEE_EMPLOYEE_H
