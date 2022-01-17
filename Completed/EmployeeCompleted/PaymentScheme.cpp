#include "PaymentScheme.h"

#include "Project.h"

RegularPaymentScheme::RegularPaymentScheme(double salary, int overtime_hours)
    : salary{salary}, overtime_hours{overtime_hours}
{}

int PaymentScheme::get_total_hours() const
{
    return get_regular_hours() + get_overtime_hours();
}

double RegularPaymentScheme::get_salary() const { return salary; }

int RegularPaymentScheme::get_regular_hours() const { return 40; }

int RegularPaymentScheme::get_overtime_hours() const { return overtime_hours; }

double RegularPaymentScheme::calculate_pay(const Employee& employee) const
{
    return salary + 60.0 * overtime_hours;
}

CommissionedPaymentScheme::CommissionedPaymentScheme(const Project& project)
    : project{project}
{}

const Project& CommissionedPaymentScheme::get_project() const { return project; }

int CommissionedPaymentScheme::get_regular_hours() const { return 40; }

int CommissionedPaymentScheme::get_overtime_hours() const { return 0; }

double CommissionedPaymentScheme::calculate_pay(const Employee& employee) const
{
    return project.get_commissioned_pay();
}

FreelancePaymentScheme::FreelancePaymentScheme(int billable_hours)
    : billable_hours{billable_hours}
{}

int FreelancePaymentScheme::get_regular_hours() const { return billable_hours; }

int FreelancePaymentScheme::get_overtime_hours() const { return 0; }

double FreelancePaymentScheme::calculate_pay(const Employee& employee) const
{
    return 50.0 * billable_hours;
}
