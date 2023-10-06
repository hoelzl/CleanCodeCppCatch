
#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <iostream>
#include <memory>
#include <string>
#include <utility>

#include "AugurDB.h"
#include "Project.h"
#include "ReportPrinter.h"

namespace employee_workshop_simplified {
enum class EmployeeType
{
    regular,
    houred,
    commissioned,
};

enum class SaveResult
{
    successful,
    failed,
};

struct Employee
{
    int id;
    std::string name;
    EmployeeType type;
    double salary;          // only for regular employees
    int overtime;           // for regular employees or freelancers (payed by the hour)
    const Project& project; // only for commissioned employees
    std::shared_ptr<AugurDb> database{};
    std::shared_ptr<const ReportPrinter> printer{};

    Employee(
        int id, std::string name, EmployeeType type, double salary, int overtime,
        const Project& project, std::shared_ptr<AugurDb> database,
        std::shared_ptr<const ReportPrinter> printer)
        : id{id}
        , name{std::move(name)}
        , type{type}
        , salary{salary}
        , overtime{overtime}
        , project{project}
        , database{std::move(database)}
        , printer{std::move(printer)}
    {}

    [[nodiscard]] double calculate_pay() const;
    [[nodiscard]] int report_hours() const;
    void print_report() const;
    [[nodiscard]] SaveResult save_employee() const; // save to database
};
} // namespace employee_workshop_simplified
#endif // EMPLOYEE_EMPLOYEE_H
