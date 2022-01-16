#pragma once
#ifndef EMPLOYEE_COMPLETED_PAYMENT_SCHEME
#define EMPLOYEE_COMPLETED_PAYMENT_SCHEME

class Employee;
class Project;

class PaymentScheme
{
public:
    virtual int get_regular_hours() const = 0;
    virtual int get_overtime_hours() const = 0;
    int get_total_hours() const;

    virtual double calculate_pay(const Employee& employee) const = 0;
};

class RegularPaymentScheme : public PaymentScheme
{
    double salary{};
    int overtime_hours{};

public:
    RegularPaymentScheme(double salary, int overtime_hours);

    double get_salary() const;

    virtual int get_regular_hours() const override;
    virtual int get_overtime_hours() const override;
    virtual double calculate_pay(const Employee& employee) const override;
};

class CommissionedPaymentScheme : public PaymentScheme
{
    const Project& project;

public:
    CommissionedPaymentScheme(const Project& project);

    const Project& get_project() const;

    virtual int get_regular_hours() const override;
    virtual int get_overtime_hours() const override;
    virtual double calculate_pay(const Employee& employee) const override;
};

class FreelancePaymentScheme : public PaymentScheme
{
    int billable_hours;

public:
    FreelancePaymentScheme(int billable_hours);

    virtual int get_regular_hours() const override;
    virtual int get_overtime_hours() const override;
    virtual double calculate_pay(const Employee& employee) const override;
};

#endif//EMPLOYEE_COMPLETED_PAYMENT_SCHEME
