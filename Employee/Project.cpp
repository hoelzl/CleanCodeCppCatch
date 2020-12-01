#include "Project.h"
#include <utility>

Project::Project(std::string name, double assets)
    : name(std::move(name)), assets(assets)
{
}

double Project::get_assets() const
{
    return assets;
}
