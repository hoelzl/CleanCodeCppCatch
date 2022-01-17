#pragma once
#ifndef EMPLOYEE_COMPLETED_PAYMENT_SCHEME
#define EMPLOYEE_COMPLETED_PAYMENT_SCHEME

class Employee;
class Project;

class PaymentScheme
{
public:
    PaymentScheme() = default;
    PaymentScheme(const PaymentScheme& other) = delete;
    PaymentScheme(PaymentScheme&& other) noexcept = delete;
    PaymentScheme& operator=(const PaymentScheme& other) = delete;
    PaymentScheme& operator=(PaymentScheme&& other) noexcept = delete;
    virtual ~PaymentScheme() = default;

    [[nodiscard]] virtual int get_regular_hours() const = 0;
    [[nodiscard]] virtual int get_overtime_hours() const = 0;
    [[nodiscard]] int get_total_hours() const;

    [[nodiscard]] virtual double calculate_pay(const Employee& employee) const = 0;
};

class RegularPaymentScheme : public PaymentScheme
{
    double salary{};
    int overtime_hours{};

public:
    RegularPaymentScheme(double salary, int overtime_hours);

    [[nodiscard]] double get_salary() const;

    [[nodiscard]] int get_regular_hours() const override;
    [[nodiscard]] int get_overtime_hours() const override;
    [[nodiscard]] double calculate_pay(const Employee& employee) const override;
};

class CommissionedPaymentScheme : public PaymentScheme
{
    const Project& project;

public:
    CommissionedPaymentScheme(const Project& project);

    [[nodiscard]] const Project& get_project() const;

    [[nodiscard]] int get_regular_hours() const override;
    [[nodiscard]] int get_overtime_hours() const override;
    [[nodiscard]] double calculate_pay(const Employee& employee) const override;
};

class FreelancePaymentScheme : public PaymentScheme
{
    int billable_hours;

public:
    FreelancePaymentScheme(int billable_hours);

    [[nodiscard]] int get_regular_hours() const override;
    [[nodiscard]] int get_overtime_hours() const override;
    [[nodiscard]] double calculate_pay(const Employee& employee) const override;
};

#endif // EMPLOYEE_COMPLETED_PAYMENT_SCHEME
