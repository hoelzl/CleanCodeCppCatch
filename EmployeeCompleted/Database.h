#pragma once
#ifndef EMPLOYEE_COMPLETED_DATABASE_H
#define EMPLOYEE_COMPLETED_DATABASE_H

#include "AugurDB.h"
#include <iostream>

using namespace std::string_literals;

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

    virtual SaveResult save_employee(const Employee& employee) = 0;
};

#endif//EMPLOYEE_COMPLETED_DATABASE_H