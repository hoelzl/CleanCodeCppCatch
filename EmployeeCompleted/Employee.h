#pragma once
#ifndef EMPLOYEE_COMPLETED_EMPLOYEE_H
#define EMPLOYEE_COMPLETED_EMPLOYEE_H

#include "Database.h"
#include "Project.h"
#include "ReportPrinter.h"
#include <string>

class Employee
{
private:
    int id;
    std::string name;

    std::shared_ptr<const ReportPrinter> report_printer;
    std::shared_ptr<Database> database;

public:
    Employee(int id, std::string name,
             std::shared_ptr<const ReportPrinter> report_printer,
             std::shared_ptr<Database> database);
    virtual ~Employee() = default;

    int get_id() const;
    const std::string& get_name() const;

    virtual double calculate_pay() const = 0;
    virtual int report_hours() const = 0;
    void print_report() const;
    SaveResult save_employee() const;
};

class RegularEmployee : public Employee
{
private:
    double salary{};
    int overtime{};

public:
    RegularEmployee(int id, std::string name, double salary, int overtime,
                    std::shared_ptr<const ReportPrinter> report_printer,
                    std::shared_ptr<Database> database);
    double get_salary() const;
    int get_overtime() const;

    virtual double calculate_pay() const override;
    virtual int report_hours() const override;
};

class CommissionedEmployee : public Employee
{
private:
    const Project& project;

public:
    CommissionedEmployee(int id, std::string name, const Project& project,
                         std::shared_ptr<const ReportPrinter> report_printer,
                         std::shared_ptr<Database> database);
    const Project& get_project() const;
    virtual double calculate_pay() const override;
    virtual int report_hours() const override;
};


class FreelanceEmployee : public Employee
{
private:
    int billable_hours{};

public:
    FreelanceEmployee(int id, std::string name, int billable_hours,
                   std::shared_ptr<const ReportPrinter> report_printer,
                   std::shared_ptr<Database> database);

    int get_billable_hours() const;
    virtual double calculate_pay() const override;
    virtual int report_hours() const override;
};


#endif//EMPLOYEE_COMPLETED_EMPLOYEE_H