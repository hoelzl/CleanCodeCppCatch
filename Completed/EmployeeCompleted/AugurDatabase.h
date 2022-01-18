#ifndef EMPLOYEE_COMPLETED_AUGUR_DATABASE_H
#define EMPLOYEE_COMPLETED_AUGUR_DATABASE_H

#include <memory>

#include "AugurDB.h"
#include "Database.h"

namespace employee_completed {
class AugurDatabase : public Database
{
    std::shared_ptr<AugurDb> augur_db{};

public:
    AugurDatabase(std::shared_ptr<AugurDb> augur_db);

    SaveResult save_employee(const Employee& employee) override;
};

} // namespace employee_completed
#endif // EMPLOYEE_COMPLETED_AUGUR_DATABASE_H
