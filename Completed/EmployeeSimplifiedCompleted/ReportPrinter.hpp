// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef REPORTPRINTER_HPP
#define REPORTPRINTER_HPP

#include <iostream>

namespace employee_completed_simplified {
struct Employee;

struct ReportPrinter
{
    ReportPrinter() = default;

    ReportPrinter(const ReportPrinter& other) = delete;
    ReportPrinter(ReportPrinter&& other) noexcept = delete;
    ReportPrinter& operator=(const ReportPrinter& other) = delete;
    ReportPrinter& operator=(ReportPrinter&& other) noexcept = delete;
    virtual ~ReportPrinter() = default;

    virtual void print_report(const Employee& employee) const = 0;
};

struct PlainTextReportPrinter : public ReportPrinter
{
    explicit PlainTextReportPrinter(std::ostream& os) : os{os} {}

    void print_report(const Employee& employee) const override;

    std::ostream& os;
};

} // namespace employee_completed_simplified

#endif // REPORTPRINTER_HPP