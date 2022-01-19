// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef PAYMENTSCHEME_HPP
#define PAYMENTSCHEME_HPP

#include "Project.hpp"

namespace employee_completed_simplified {
enum class EmployeeType
{
    regular,
    houred,
    commissioned,
};

struct PaymentScheme
{
    PaymentScheme() = default;
    PaymentScheme(const PaymentScheme& other) = delete;
    PaymentScheme(PaymentScheme&& other) noexcept = delete;
    PaymentScheme& operator=(const PaymentScheme& other) = delete;
    PaymentScheme& operator=(PaymentScheme&& other) noexcept = delete;
    virtual ~PaymentScheme() = default;

    [[nodiscard]] virtual double calculate_pay() const = 0;
    [[nodiscard]] virtual int report_hours() const = 0;
};

struct RegularPaymentScheme : PaymentScheme
{
    double salary;
    int overtime;

    RegularPaymentScheme(double salary, int overtime)
        : salary{salary}, overtime{overtime}
    {}

    [[nodiscard]] double calculate_pay() const override;
    [[nodiscard]] int report_hours() const override;
};

struct FreelancePaymentScheme : PaymentScheme
{
    int billed_hours;

    explicit FreelancePaymentScheme(int overtime) : billed_hours{overtime} {}

    [[nodiscard]] double calculate_pay() const override;
    [[nodiscard]] int report_hours() const override;
};

struct CommissionedPaymentScheme : PaymentScheme
{
    const Project& project;

    explicit CommissionedPaymentScheme(const Project& project) : project{project} {}

    [[nodiscard]] double calculate_pay() const override;
    [[nodiscard]] int report_hours() const override;
};

} // namespace employee_completed_simplified

#endif // PAYMENTSCHEME_HPP