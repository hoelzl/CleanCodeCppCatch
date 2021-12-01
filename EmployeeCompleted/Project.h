#pragma once
#ifndef EMPLOYEE_COMPLETED_PROJECT_H
#define EMPLOYEE_COMPLETED_PROJECT_H

#include <string>

class Project
{
private:
    std::string name;
    double assets;
    double commissioned_pay;

public:
    Project(std::string name, double assets, double commissioned_pay);

    double get_assets() const;
    double get_commissioned_pay() const;
};


#endif//EMPLOYEE_COMPLETED_PROJECT_H
