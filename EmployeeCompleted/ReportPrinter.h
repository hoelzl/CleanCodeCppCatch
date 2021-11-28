# pragma once

#include <iostream>

class Employee;

class ReportPrinter
{
    virtual ~ReportPrinter() = default;

    virtual void print_report(Employee& employee);
};
