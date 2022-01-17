#pragma once
#ifndef EMPLOYEE_COMPLETED_DATABASE_H
#define EMPLOYEE_COMPLETED_DATABASE_H

#include <iostream>

#include "AugurDB.h"

using namespace std::string_literals;

class Employee;

enum class SaveResult
{
    successful,
    failed,
};

class Database
{
public:
    Database() = default;
    Database(const Database& other) = delete;
    Database(Database&& other) noexcept = delete;
    Database& operator=(const Database& other) = delete;
    Database& operator=(Database&& other) noexcept = delete;
    virtual ~Database() = default;

    virtual SaveResult save_employee(const Employee& employee) = 0;
};

#endif // EMPLOYEE_COMPLETED_DATABASE_H