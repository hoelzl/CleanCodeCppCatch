#pragma once
#ifndef EMPLOYEE_COMPLETED_DATABASE_H
#define EMPLOYEE_COMPLETED_DATABASE_H

#include <iostream>

class Employee;

enum class SaveResult
{
    Successful,
    Failed,
};

class Database
{
public:
    virtual ~Database() = default;

    virtual SaveResult save_employee(const Employee& employee)
    {
        // This has to know about the different types of employees...
        return SaveResult::Successful;
    }
};

#endif//EMPLOYEE_COMPLETED_DATABASE_H