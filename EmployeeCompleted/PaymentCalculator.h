#pragma once

class PaymentCalculator
{
public:
    virtual ~PaymentCalculator() = default;

    virtual double calculate_pay(const Employee& employee)
    {
        return 1000.0;
    }
};