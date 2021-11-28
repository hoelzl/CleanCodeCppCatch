#pragma once

#include <string>

class Employee;

class HourReporter
{
public:
    virtual ~HourReporter() = default;

    virtual std::string report_hours(const Employee& employee) const
    {
        return "40 hours";
    }
};