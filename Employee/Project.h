#ifndef EMPLOYEE_PROJECT_H
#define EMPLOYEE_PROJECT_H

#include <string>

class Project
{
private:
    std::string name{};
    double assets{};
    double commissioned_pay{};

public:
    Project(std::string name, double assets = 20000.0,
            double commissioned_pay = 1500.0);

    const std::string& get_name() const;
    double get_assets() const;
    double get_commissioned_pay() const;
};


#endif// EMPLOYEE_PROJECT_H
