#include "AugurDatabase.h"
#include "Employee.h"

AugurDatabase::AugurDatabase(std::shared_ptr<AugurDB> augur_db)
    : augur_db{std::move(augur_db)}
{
}

SaveResult AugurDatabase::save_employee(const Employee& employee)
{
    augur_db->start_transaction();
    SaveResult result{SaveResult::Successful};

    augur_db->store_field("id"s, employee.get_id());
    augur_db->store_field("name"s, employee.get_name());

    if (auto* regular_employee{
                dynamic_cast<const RegularEmployee*>(&employee)}) {
        augur_db->store_field("salary"s, regular_employee->get_salary());
        augur_db->store_field("overtime"s, regular_employee->get_overtime());
    } else if (auto* commissioned_employee{
                       dynamic_cast<const CommissionedEmployee*>(&employee)}) {
        augur_db->store_field("project"s,
                              commissioned_employee->get_project().get_name());
    } else if (auto* freelance_employee{
                       dynamic_cast<const FreelanceEmployee*>(&employee)}) {
        augur_db->store_field("billable_hours"s,
                              freelance_employee->get_billable_hours());
    } else {
        // Abort transaction, etc.
        result = SaveResult::Failed;
    }
    augur_db->commit_transaction();

    return result;
}
