#include "Employee.h"
#include "ReportPrinter.h"

namespace employee_workshop_simplified {

void PlainTextReportPrinter::print_report(const Employee& employee) const
{
    os << employee.name << " worked " << employee.report_hours() << " hours.\n";
}

}
