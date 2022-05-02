// Copyright (c) 2022 Dr. Matthias Hölzl.

// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once
#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <memory>
#include <stdexcept>

enum class EmployeeType
{
    commissioned,
    hourly
};

struct EmployeeWithSwitch
{
    EmployeeType employee_type{EmployeeType::commissioned};

    [[nodiscard]] int compute_salary() const
    {
        switch (employee_type) {
        case EmployeeType::commissioned: return 4500;
        case EmployeeType::hourly: return 1500;
        }
        throw std::domain_error("Unknown employee type.");
    }
};

void test_employee_with_switch();

struct Employee
{
    virtual ~Employee() = default;
    [[nodiscard]] virtual int compute_salary() const = 0;
};

struct CommissionedEmployee : public Employee
{
    [[nodiscard]] int compute_salary() const override { return 4500; }
};

struct HourlyEmployee : public Employee
{
    [[nodiscard]] int compute_salary() const override { return 1500; }
};

std::unique_ptr<Employee> make_employee(EmployeeType employee_type);

void test_employee();

#endif // CLASSES_HPP
