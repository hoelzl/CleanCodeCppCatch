#include "classes.hpp"

#include <iostream>

void test_employee_with_switch()
{
    constexpr EmployeeWithSwitch e1{EmployeeType::commissioned};
    constexpr EmployeeWithSwitch e2{EmployeeType::hourly};
    constexpr EmployeeWithSwitch e3{static_cast<EmployeeType>(10)};

    try {
        std::cout << "Salary for e1: " << e1.compute_salary() << '\n';
        std::cout << "Salary for e2: " << e2.compute_salary() << '\n';
        std::cout << "Salary for e3: " << e3.compute_salary() << '\n';
    }
    catch (std::domain_error& err) {
        std::cerr << "Caught error: " << err.what() << '\n';
    }
}

std::unique_ptr<Employee> make_employee(EmployeeType employee_type)
{
    switch (employee_type) {
    case EmployeeType::commissioned: return std::make_unique<CommissionedEmployee>();
    case EmployeeType::hourly: return std::make_unique<HourlyEmployee>();
    }
    throw std::domain_error{"Unknown employee type."};
}

void test_employee_without_error_handling(bool try_invalid_id)
{
    const auto e1{make_employee(EmployeeType::commissioned)};
    const auto e2{make_employee(EmployeeType::hourly)};
    if (try_invalid_id) {
        const auto e3{make_employee(static_cast<EmployeeType>(10))};
    }

    std::cout << "Salary for e1: " << e1->compute_salary() << '\n';
    std::cout << "Salary for e2: " << e2->compute_salary() << '\n';
}

void test_employee()
{
    try {
        test_employee_without_error_handling(true);
    }
    catch (std::domain_error& err) {
        std::cerr << "Caught error: " << err.what() << '\n';
    }
    test_employee_without_error_handling(false);
}