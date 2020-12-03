# pragma once

class ReportPrinter
{
    virtual ~ReportPrinter() = default;

    virtual void print_report(Employee& employee)
    {
        std::cout << "Report for " + Employee.get_name();
    }
};
