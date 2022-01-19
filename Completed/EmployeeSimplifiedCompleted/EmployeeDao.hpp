// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef EMPLOYEEDAO_HPP
#define EMPLOYEEDAO_HPP

#include <memory>

#include "AugurDB.hpp"

namespace employee_completed_simplified {
struct PaymentScheme;
struct Employee;

enum class SaveResult
{
    successful,
    failed,
};

SaveResult operator&(SaveResult lhs, SaveResult rhs);
SaveResult operator|(SaveResult lhs, SaveResult rhs);
SaveResult operator!(SaveResult arg);
SaveResult& operator&=(SaveResult& lhs, SaveResult rhs);
SaveResult& operator|=(SaveResult& lhs, SaveResult rhs);

struct EmployeeDao
{
    EmployeeDao() = default;
    EmployeeDao(const EmployeeDao& other) = delete;
    EmployeeDao(EmployeeDao&& other) noexcept = delete;
    EmployeeDao& operator=(const EmployeeDao& other) = delete;
    EmployeeDao& operator=(EmployeeDao&& other) noexcept = delete;
    virtual ~EmployeeDao() = default;

    virtual SaveResult save(const Employee& employee) = 0;

    virtual SaveResult save_in_transaction(const Employee& employee) = 0;
    virtual SaveResult save_in_transaction(const PaymentScheme& payment_scheme) = 0;
};

struct EmployeeDaoForAugurDb final : public EmployeeDao
{
    explicit EmployeeDaoForAugurDb(std::shared_ptr<AugurDb> db)
        : database{std::move(db)}
    {}

    SaveResult save(const Employee& employee) override;
    SaveResult save_in_transaction(const Employee& employee) override;
    SaveResult save_in_transaction(const PaymentScheme& payment_scheme) override;

    std::shared_ptr<AugurDb> database;
};

} // namespace employee_completed_simplified

#endif // EMPLOYEEDAO_HPP