#include "PaymentScheme.hpp"

#include <string>

namespace employee_completed_simplified {

using namespace std::literals::string_literals;

double RegularPaymentScheme::calculate_pay() const { return salary + 60.0 * overtime; }
int RegularPaymentScheme::report_hours() const { return 40 + overtime; }

double FreelancePaymentScheme::calculate_pay() const { return 50.0 * billed_hours; }
int FreelancePaymentScheme::report_hours() const { return billed_hours; }

double CommissionedPaymentScheme::calculate_pay() const
{
    return project.commissioned_pay;
}
int CommissionedPaymentScheme::report_hours() const { return 40; }

} // namespace employee_completed_simplified
