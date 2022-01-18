#include "AugurDatabase.h"

#include "Employee.h"
#include "Project.h"

namespace employee_completed {
AugurDatabase::AugurDatabase(std::shared_ptr<AugurDb> augur_db)
    : augur_db{std::move(augur_db)}
{}

SaveResult AugurDatabase::save_employee(const Employee& employee)
{
    augur_db->start_transaction();
    SaveResult result{SaveResult::successful};

    augur_db->store_field("id"s, employee.get_id());
    augur_db->store_field("name"s, employee.get_name());
    const PaymentScheme& payment_scheme{employee.get_payment_scheme()};

    if (auto* regular_payment_scheme{
            dynamic_cast<const RegularPaymentScheme*>(&payment_scheme)}) {
        augur_db->store_field("salary"s, regular_payment_scheme->get_salary());
        augur_db->store_field(
            "overtime"s, regular_payment_scheme->get_overtime_hours());
    }
    else if (auto* commissioned_payment_scheme{
                 dynamic_cast<const CommissionedPaymentScheme*>(&payment_scheme)}) {
        augur_db->store_field(
            "project"s, commissioned_payment_scheme->get_project().get_name());
    }
    else if (auto* freelance_payment_scheme{
                 dynamic_cast<const FreelancePaymentScheme*>(&payment_scheme)}) {
        augur_db->store_field(
            "billable_hours"s, freelance_payment_scheme->get_regular_hours());
    }
    else {
        // Abort transaction, etc.
        result = SaveResult::failed;
    }
    augur_db->commit_transaction();

    return result;
}
} // namespace employee_completed