#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Project.h"

using namespace std::string_literals;
using namespace employee_workshop;

SCENARIO("Some Company")
{
    std::shared_ptr<AugurDb> database{std::make_shared<AugurDb>()};

    GIVEN("any kind of employee and project")
    {
        Project project{"The Big Project", 5000.0};
        Employee employee{
            123,     "Jack Hammer"s, EmployeeType::commissioned, 2000.0, 10,
            project, database};

        THEN("the employee's ID is correct") { CHECK(employee.get_id() == 123); }

        THEN("the employee's name is correct")
        {
            CHECK(employee.get_name() == "Jack Hammer");
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::successful);
            DatabaseRecord db_record{{"id"s, "name"s, "type"s, "salary"s, "project"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(database->get_records() == expected_records);
        }
    }

    GIVEN("a regular employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{123,     "Jill Connor"s, EmployeeType::regular, 2000.0, 10,
                          project, database};

        THEN("the report hours are correct") { CHECK(employee.report_hours() == 50); }

        THEN("the report is correct")
        {
            std::stringstream os{};
            employee.print_report(os);
            CHECK(os.str() == "Jill Connor worked 50 hours.\n"s);
        }

        THEN("the employee's payment is computed correctly")
        {
            CHECK(employee.calculate_pay() == 2600.0);
        }
    }

    GIVEN("a freelance employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{123,     "Jill Connor"s, EmployeeType::houred, 2000.0, 35,
                          project, database};

        THEN("the report hours are correct") { CHECK(employee.report_hours() == 35); }

        THEN("the report is correct")
        {
            std::stringstream os{};
            employee.print_report(os);
            CHECK(os.str() == "Jill Connor worked 35 hours.\n"s);
        }

        THEN("the employee's payment is computed correctly")
        {
            CHECK(employee.calculate_pay() == 1750.0);
        }
    }

    GIVEN("a commissioned employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{
            123,     "Jill Connor"s, EmployeeType::commissioned, 2000.0, 35,
            project, database};

        THEN("the report hours are correct") { CHECK(employee.report_hours() == 40); }

        THEN("the report is correct")
        {
            std::stringstream os{};
            employee.print_report(os);
            CHECK(os.str() == "Jill Connor worked 40 hours.\n"s);
        }

        THEN("the employee's payment is computed according to the project")
        {
            CHECK(employee.calculate_pay() == 1200.0);
        }
    }

    GIVEN("an employee with invalid type")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{
            123,     "Jill Connor"s, static_cast<EmployeeType>(123), 2000.0, 35,
            project, database};

        THEN("report_hours() raises an exception")
        {
            CHECK_THROWS_AS(employee.report_hours(), std::invalid_argument);
        }

        THEN("print_report() raises an exception")
        {
            CHECK_THROWS_AS(employee.print_report(), std::invalid_argument);
        }

        THEN("calculate_pay() raises an exception")
        {
            CHECK_THROWS_AS(employee.calculate_pay(), std::invalid_argument);
        }
    }
}
