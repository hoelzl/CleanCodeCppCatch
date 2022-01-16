#pragma once

#include <iostream>
#include <string>

class Employee;

class ReportPrinter
{
    std::ostream& os;

public:
    explicit ReportPrinter(std::ostream& os = std::cout) : os{os}
    {
    }

    virtual ~ReportPrinter() = default;

    virtual void print_report(const Employee& employee) const;
};