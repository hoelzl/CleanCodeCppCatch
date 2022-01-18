#pragma once
#ifndef EMPLOYEE_COMPLETED_PROJECT_H
#define EMPLOYEE_COMPLETED_PROJECT_H

#include <string>

namespace employee_completed {
class Project
{
private:
    std::string name;
    double assets;
    double commissioned_pay;

public:
    Project(std::string name, double assets, double commissioned_pay);

    [[nodiscard]] const std::string& get_name() const;
    [[nodiscard]] double get_assets() const;
    [[nodiscard]] double get_commissioned_pay() const;
};

} // namespace employee_completed
#endif // EMPLOYEE_COMPLETED_PROJECT_H
