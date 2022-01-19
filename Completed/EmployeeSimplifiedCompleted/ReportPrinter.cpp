#include "ReportPrinter.hpp"

#include "Employee.hpp"

void employee_completed_simplified::PlainTextReportPrinter::print_report(
    const Employee& employee) const
{
    os << employee.name << " worked " << employee.report_hours() << " hours.\n";
}
