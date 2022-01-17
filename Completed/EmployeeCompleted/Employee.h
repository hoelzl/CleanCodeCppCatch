#pragma once
#ifndef EMPLOYEE_COMPLETED_EMPLOYEE_H
#define EMPLOYEE_COMPLETED_EMPLOYEE_H

#include <memory>
#include <string>

#include "Database.h"
#include "PaymentScheme.h"
#include "ReportPrinter.h"

class Employee
{
private:
    int id;
    std::string name;

    std::unique_ptr<const PaymentScheme> payment_scheme;
    std::shared_ptr<const ReportPrinter> report_printer;
    std::shared_ptr<Database> database;

public:
    Employee(
        int id, std::string name, std::unique_ptr<const PaymentScheme> payment_scheme,
        std::shared_ptr<const ReportPrinter> report_printer,
        std::shared_ptr<Database> database);

    [[nodiscard]] int get_id() const;
    [[nodiscard]] const std::string& get_name() const;
    [[nodiscard]] const PaymentScheme& get_payment_scheme() const;

    [[nodiscard]] double calculate_pay() const;
    [[nodiscard]] int report_hours() const;
    void print_report() const;
    [[nodiscard]] SaveResult save_employee() const;
};

#endif // EMPLOYEE_COMPLETED_EMPLOYEE_H