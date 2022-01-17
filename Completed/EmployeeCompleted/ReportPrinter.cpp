#include "ReportPrinter.h"

#include "Employee.h"

void ReportPrinter::print_report(const Employee& employee) const
{
    os << employee.get_name() << " worked " << employee.report_hours() << " hours.\n";
}
