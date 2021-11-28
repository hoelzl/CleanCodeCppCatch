#include "ReportPrinter.h"
#include "Employee.h"

inline void ReportPrinter::print_report(Employee& employee)
{
    std::cout << "Report for " + employee.get_name();
}
