#ifndef EMPLOYEE_COMPLETED_AUGUR_DATABASE_H
#define EMPLOYEE_COMPLETED_AUGUR_DATABASE_H

#include "AugurDB.h"
#include "Database.h"
#include <memory>

class AugurDatabase : public Database
{
    std::shared_ptr<AugurDB> augur_db{};

public:
    AugurDatabase(std::shared_ptr<AugurDB> augur_db);

    virtual SaveResult save_employee(const Employee& employee) override;
};

#endif EMPLOYEE_COMPLETED_AUGUR_DATABASE_H
