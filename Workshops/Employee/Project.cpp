#include "Project.h"
#include <utility>

Project::Project(std::string name, double assets, double commissioned_pay)
    : name{std::move(name)}, assets{assets}, commissioned_pay{commissioned_pay}
{
}

const std::string& Project::get_name() const
{
    return name;
}

double Project::get_assets() const
{
    return assets;
}

double Project::get_commissioned_pay() const
{
    return commissioned_pay;
}
