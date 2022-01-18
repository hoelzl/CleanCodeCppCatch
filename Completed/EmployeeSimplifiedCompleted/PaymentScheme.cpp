#include "PaymentScheme.hpp"

#include <string>

namespace employee_completed_simplified {

using namespace std::literals::string_literals;

double RegularPaymentScheme::calculate_pay() const { return salary + 60.0 * overtime; }
int RegularPaymentScheme::report_hours() const { return 40 + overtime; }
void RegularPaymentScheme::save_fields(const std::shared_ptr<AugurDb>& database)
{
    database->store_field("payment_scheme"s, "RegularPaymentScheme");
    database->store_field("salary"s, salary);
    database->store_field("overtime"s, overtime);
}

double FreelancePaymentScheme::calculate_pay() const { return 50.0 * billed_hours; }
int FreelancePaymentScheme::report_hours() const { return billed_hours; }
void FreelancePaymentScheme::save_fields(const std::shared_ptr<AugurDb>& database)
{
    database->store_field("payment_scheme"s, "FreelancePaymentScheme");
    database->store_field("billed_hours", billed_hours);
}

double CommissionedPaymentScheme::calculate_pay() const
{
    return project.commissioned_pay;
}
int CommissionedPaymentScheme::report_hours() const { return 40; }
void CommissionedPaymentScheme::save_fields(const std::shared_ptr<AugurDb>& database)
{
    database->store_field("payment_scheme"s, "CommissionedPaymentScheme");
    database->store_field("project", project.name);    
}

} // namespace employee_completed_simplified
