#ifndef EMPLOYEE_PROJECT_H
#define EMPLOYEE_PROJECT_H

#include <string>
namespace employee_workshop {
class Project
{
private:
    std::string name{};
    double assets{};
    double commissioned_pay{};

public:
    Project(
        std::string name, double assets = 20000.0, double commissioned_pay = 1500.0);

    [[nodiscard]] const std::string& get_name() const;
    [[nodiscard]] double get_assets() const;
    [[nodiscard]] double get_commissioned_pay() const;
};
}

#endif // EMPLOYEE_PROJECT_H
