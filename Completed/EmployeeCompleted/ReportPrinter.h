#pragma once

#include <iostream>

class Employee;

class ReportPrinter
{
    std::ostream& os;

public:
    explicit ReportPrinter(std::ostream& os = std::cout) : os{os} {}
    ReportPrinter(const ReportPrinter& other) = delete;
    ReportPrinter(ReportPrinter&& other) noexcept = delete;
    ReportPrinter& operator=(const ReportPrinter& other) = delete;
    ReportPrinter& operator=(ReportPrinter&& other) noexcept = delete;
    virtual ~ReportPrinter() = default;

    virtual void print_report(const Employee& employee) const;
};