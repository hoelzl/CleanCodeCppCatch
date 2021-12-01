#pragma once
#ifndef EMPLOYEE_COMPLETED_EMPLOYEE_H
#define EMPLOYEE_COMPLETED_EMPLOYEE_H

#include "Database.h"
#include "PaymentScheme.h"
#include "Project.h"
#include "ReportPrinter.h"
#include <memory>
#include <string>

class Employee
{
private:
    int id;
    std::string name;

    std::unique_ptr<PaymentScheme> payment_scheme;
    std::shared_ptr<const ReportPrinter> report_printer;
    std::shared_ptr<Database> database;

public:
    Employee(int id, std::string name,
             std::unique_ptr<PaymentScheme> payment_scheme,
             std::shared_ptr<const ReportPrinter> report_printer,
             std::shared_ptr<Database> database);
    virtual ~Employee() = default;

    int get_id() const;
    const std::string& get_name() const;
    const PaymentScheme& get_payment_scheme() const;

    double calculate_pay() const;
    int report_hours() const;
    void print_report() const;
    SaveResult save_employee() const;
};

#endif//EMPLOYEE_COMPLETED_EMPLOYEE_H