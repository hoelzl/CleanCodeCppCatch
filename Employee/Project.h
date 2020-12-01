#ifndef EMPLOYEE_PROJECT_H
#define EMPLOYEE_PROJECT_H

#include <string>

class Project
{
private:
    std::string name;
    double assets;
public:
    Project(std::string  name, double assets);
    double get_assets() const;
};


#endif//EMPLOYEE_PROJECT_H
