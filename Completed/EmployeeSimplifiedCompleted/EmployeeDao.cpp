#include "EmployeeDao.hpp"

#include <string>

#include "Employee.hpp"
#include "PaymentScheme.hpp"

namespace employee_completed_simplified {

using namespace std::string_literals;

SaveResult operator&(SaveResult lhs, SaveResult rhs)
{
    if (lhs == SaveResult::successful) {
        return rhs;
    }
    return SaveResult::failed;
}
SaveResult operator|(SaveResult lhs, SaveResult rhs)
{
    if (lhs == SaveResult::failed) {
        return rhs;
    }
    return SaveResult::successful;
}
SaveResult operator!(SaveResult arg)
{
    if (arg == SaveResult::failed) {
        return SaveResult::successful;
    }
    return SaveResult::failed;
}

SaveResult& operator&=(SaveResult& lhs, SaveResult rhs) { return lhs = lhs & rhs; }
SaveResult& operator|=(SaveResult& lhs, SaveResult rhs) { return lhs = lhs | rhs; }

SaveResult EmployeeDaoForAugurDb::save(const Employee& employee)
{
    database->start_transaction();
    SaveResult result{save_in_transaction(employee)};
    result &= save_in_transaction(*employee.payment_scheme);
    database->commit_transaction();
    return result;
}

SaveResult EmployeeDaoForAugurDb::save_in_transaction(const Employee& employee)
{
    database->store_field("id"s, employee.id);
    database->store_field("name"s, employee.name);
    return SaveResult::successful;
}

SaveResult
EmployeeDaoForAugurDb::save_in_transaction(const PaymentScheme& payment_scheme)
{
    if (auto* regular_ps{dynamic_cast<const RegularPaymentScheme*>(&payment_scheme)}) {
        database->store_field("payment_scheme"s, "RegularPaymentScheme");
        database->store_field("salary"s, regular_ps->salary);
        database->store_field("overtime"s, regular_ps->overtime);
        return SaveResult::successful;
    }
    if (auto* freelance_ps{
            dynamic_cast<const FreelancePaymentScheme*>(&payment_scheme)}) {
        database->store_field("payment_scheme"s, "FreelancePaymentScheme");
        database->store_field("billed_hours"s, freelance_ps->billed_hours);
        return SaveResult::successful;
    }
    if (auto* commissioned_ps{
            dynamic_cast<const CommissionedPaymentScheme*>(&payment_scheme)}) {
        database->store_field("payment_scheme"s, "CommissionedPaymentScheme");
        database->store_field("project"s, commissioned_ps->project.name);
        return SaveResult::successful;
    }
    return SaveResult::failed;
}

} // namespace employee_completed_simplified
