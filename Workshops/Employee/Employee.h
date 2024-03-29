
#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <iostream>
#include <memory>
#include <string>

#include "AugurDB.h"
#include "Project.h"

namespace employee_workshop {
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

class Employee
{
private:
    int id;
    std::string name;
    EmployeeType type;
    double salary;          // only for regular employees
    int overtime;           // for regular employees or freelancers (payed by the hour)
    const Project& project; // only for commissioned employees
    std::shared_ptr<AugurDb> database{};

public:
    Employee(
        int id, std::string name, EmployeeType type, double salary, int overtime,
        const Project& project, std::shared_ptr<AugurDb> database);

    int get_id() const;
    const std::string& get_name() const;
    const Project& get_project() const;

    double calculate_pay() const;
    int report_hours() const;
    void print_report(std::ostream& os = std::cout) const;
    SaveResult save_employee() const; // save to database
};

} // namespace employee_workshop
#endif // EMPLOYEE_EMPLOYEE_H
