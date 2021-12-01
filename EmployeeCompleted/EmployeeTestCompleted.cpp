#define CATCH_CONFIG_MAIN
#include "AugurDB.h"
#include "AugurDatabase.h"
#include "Employee.h"
#include "PaymentScheme.h"
#include "Project.h"
#include "catch.hpp"
#include <sstream>
#include <string>

using namespace std::string_literals;

SCENARIO("Some Company")
{
    std::shared_ptr<AugurDB> augur_db{std::make_shared<AugurDB>()};
    std::shared_ptr<Database> database{
            std::make_shared<AugurDatabase>(augur_db)};

    std::stringstream report_stream{};
    std::shared_ptr<const ReportPrinter> report_printer{
            std::make_shared<ReportPrinter>(report_stream)};

    GIVEN("any kind of employee")
    {
        Employee employee{123, "Jack Hammer"s,
                          std::make_unique<RegularPaymentScheme>(2000.0, 10),
                          report_printer, database};

        THEN("the employee's ID is correct")
        {
            CHECK(employee.get_id() == 123);
        }

        THEN("The employee's name is correct")
        {
            CHECK(employee.get_name() == "Jack Hammer");
        }
    }

    GIVEN("a regular employee")
    {
        Employee employee{123, "Jill Connor"s,
                          std::make_unique<RegularPaymentScheme>(2000.0, 10),
                          report_printer, database};

        THEN("the report hours are correct")
        {
            CHECK(employee.report_hours() == 50);
        }

        THEN("the report is correct")
        {
            employee.print_report();
            CHECK(report_stream.str() == "Jill Connor worked 50 hours.\n"s);
        }

        THEN("the employee's payment is computed correctly")
        {
            CHECK(employee.calculate_pay() == 2600.0);
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::Successful);
            DatabaseRecord db_record{{"id"s, "name"s, "salary"s, "overtime"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(augur_db->get_records() == expected_records);
        }
    }

    GIVEN("a freelance employee")
    {
        Employee employee{123, "Jill Connor"s,
                          std::make_unique<FreelancePaymentScheme>(35),
                          report_printer, database};

        THEN("the report hours are correct")
        {
            CHECK(employee.report_hours() == 35);
        }

        THEN("the report is correct")
        {
            employee.print_report();
            CHECK(report_stream.str() == "Jill Connor worked 35 hours.\n"s);
        }

        THEN("the employee's payment is computed correctly")
        {
            CHECK(employee.calculate_pay() == 1750.0);
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::Successful);
            DatabaseRecord db_record{{"id"s, "name"s, "billable_hours"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(augur_db->get_records() == expected_records);
        }
    }

    GIVEN("a commissioned employee")
    {
        Project project{"A Random Project", 10000.0, 1200.0};
        Employee employee{123, "Jill Connor"s,
                          std::make_unique<CommissionedPaymentScheme>(project),
                          report_printer, database};

        THEN("the report hours are correct")
        {
            CHECK(employee.report_hours() == 40);
        }

        THEN("the report is correct")
        {
            employee.print_report();
            CHECK(report_stream.str() == "Jill Connor worked 40 hours.\n"s);
        }

        THEN("the employee's payment is computed according to the project")
        {
            CHECK(employee.calculate_pay() == 1200.0);
        }

        THEN("saving works")
        {
            CHECK(employee.save_employee() == SaveResult::Successful);
            DatabaseRecord db_record{{"id"s, "name"s, "project"s}};
            std::vector<DatabaseRecord> expected_records{db_record};
            CHECK(augur_db->get_records() == expected_records);
        }
    }
}
