#include "salaries_completed.h"

#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void assert_valid_day_number(int day_number);

double process_salary(
    int day_number, double salary_per_day, const char* employee_name,
    std::vector<double>& all_salaries)
{
    assert_valid_day_number(day_number);
    const auto salary_after_taxes
        = compute_salary_after_taxes(day_number, salary_per_day);
    store_salary(salary_after_taxes, all_salaries);
    print_salary(day_number, salary_per_day, employee_name);
    return compute_taxes(day_number, salary_per_day);
}

void assert_valid_day_number(int day_number)
{
    if (day_number < 1 || day_number > 7) {
        throw std::domain_error("The value of day_number must be between 1 and 7.");
    }
}

double compute_salary_after_taxes(int day_number, double salary_per_day)
{
    const auto salary_before_taxes
        = compute_salary_before_taxes(day_number, salary_per_day);
    const auto taxes = compute_taxes(salary_before_taxes);
    return salary_before_taxes - taxes;
}

double compute_salary_before_taxes(int day_number, double salary_per_day)
{
    assert_valid_day_number(day_number);
    return (day_number - 1) * salary_per_day;
}

double compute_taxes(double salary_before_taxes)
{
    return salary_before_taxes * compute_tax_rate(salary_before_taxes);
}

double compute_taxes(int day_number, double salary_per_day)
{
    const auto salary_before_taxes
        = compute_salary_before_taxes(day_number, salary_per_day);
    return compute_taxes(salary_before_taxes);
}

double compute_tax_rate(double salary)
{
    if (salary <= 500.0) {
        return 0.0;
    }
    else if (salary <= 1000.0) {
        return 0.05;
    }
    else if (salary <= 2000.0) {
        return 0.1;
    }
    else {
        return 0.15;
    }
}

void store_salary(double salary, std::vector<double>& all_salaries)
{
    all_salaries.push_back(salary);
}

void print_salary(int day_number, double salary_per_day, const char* employee_name)
{
    std::cout << employee_name << " worked till "
              << compute_day_of_week_name(day_number) << " and earned $"
              << compute_salary_after_taxes(day_number, salary_per_day)
              << " this week.\n";
    std::cout << "  "
              << "Their taxes were $" << compute_taxes(day_number, salary_per_day)
              << ".";
    std::cout << std::endl;
}

const std::string& compute_day_of_week_name(int day_number)
{
    const static std::array<const std::string, 7> day_names{"Sun", "Mon", "Tue", "Wed",
                                                            "Thu", "Fri", "Sat"};
    assert_valid_day_number(day_number);
    return day_names.at(day_number - 1);
}
