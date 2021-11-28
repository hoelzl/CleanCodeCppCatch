#include <string>
#include <vector>

double process_salary(int day_number, double salary_per_day,
                      const char* employee_name,
                      std::vector<double>& all_salaries);

double compute_salary_after_taxes(int day_number, double salary_per_day);

double compute_salary_before_taxes(int day_number, double salary_per_day);

double compute_taxes(double salary_before_taxes);

double compute_taxes(int day_number, double salary_per_day);

double compute_tax_rate(double salary);

void store_salary(double salary, std::vector<double>& all_salaries);

void print_salary(int day_number, double salary_per_day,
                  const char* employee_name);

const std::string& compute_day_of_week_name(int day_number);
