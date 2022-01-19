#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <vector>

#include "Employee.hpp"
#include "EmployeeDao.hpp"
#include "PaymentScheme.hpp"
#include "Project.hpp"
#include "ReportPrinter.hpp"

using namespace std::string_literals;
using namespace employee_completed_simplified;

SCENARIO("Some Company")
{
    auto database{std::make_shared<AugurDb>()};
    std::ostringstream os{};
    auto printer{std::make_shared<PlainTextReportPrinter>(os)};

    GIVEN("any kind of employee and project")
    {
        Project project{"The Big Project", 5000.0};
        Employee employee{
            123, "Jack Hammer"s, std::make_unique<CommissionedPaymentScheme>(project),
            std::make_unique<EmployeeDaoForAugurDb>(database), printer};

        THEN("the employee's ID is correct") { CHECK(employee.id == 123); }

        THEN("the employee's name is correct")
        {
            CHECK(employee.name == "Jack Hammer");
        }
    }

    GIVEN("a regular employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{
            123, "Jill Connor"s, std::make_unique<RegularPaymentScheme>(2000.0, 10),
            std::make_unique<EmployeeDaoForAugurDb>(database), printer};

        THEN("the report hours are correct") { CHECK(employee.report_hours() == 50); }

        THEN("the report is correct")
        {
            employee.print_report();
            CHECK(os.str() == "Jill Connor worked 50 hours.\n"s);
        }

        THEN("the employee's payment is computed correctly")
        {
            CHECK(employee.calculate_pay() == 2600.0);
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::successful);
            DatabaseRecord db_record{
                {"id"s, "name"s, "payment_scheme"s, "salary"s, "overtime"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(database->get_records() == expected_records);
        }
    }

    GIVEN("a freelance employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{
            123, "Jill Connor"s, std::make_unique<FreelancePaymentScheme>(35),
            std::make_unique<EmployeeDaoForAugurDb>(database), printer};

        THEN("the report hours are correct") { CHECK(employee.report_hours() == 35); }

        THEN("the report is correct")
        {
            employee.print_report();
            CHECK(os.str() == "Jill Connor worked 35 hours.\n"s);
        }

        THEN("the employee's payment is computed correctly")
        {
            CHECK(employee.calculate_pay() == 1750.0);
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::successful);
            DatabaseRecord db_record{
                {"id"s, "name"s, "payment_scheme"s, "billed_hours"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(database->get_records() == expected_records);
        }
    }

    GIVEN("a commissioned employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{
            123, "Jill Connor"s, std::make_unique<CommissionedPaymentScheme>(project),
            std::make_unique<EmployeeDaoForAugurDb>(database), printer};

        THEN("the report hours are correct") { CHECK(employee.report_hours() == 40); }

        THEN("the report is correct")
        {
            employee.print_report();
            CHECK(os.str() == "Jill Connor worked 40 hours.\n"s);
        }

        THEN("the employee's payment is computed according to the project")
        {
            CHECK(employee.calculate_pay() == 1200.0);
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::successful);
            DatabaseRecord db_record{{"id"s, "name"s, "payment_scheme"s, "project"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(database->get_records() == expected_records);
        }
    }
}
