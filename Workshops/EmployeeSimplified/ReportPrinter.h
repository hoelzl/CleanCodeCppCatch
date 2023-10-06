// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef REPORTPRINTER_H
#define REPORTPRINTER_H

#include <iostream>

namespace employee_workshop_simplified {

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



}
#endif // REPORTPRINTER_H
