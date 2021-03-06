#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

bool is_leap_year(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

TEST_CASE("a year is not a leap year")
{
    SECTION("if it is not divisible by 4")
    {
        CHECK(!is_leap_year(1983));
    }
    SECTION("if it is divisible by 100 but not 400")
    {
        CHECK_FALSE(is_leap_year(1900));
    }
}

TEST_CASE("a year is a leap year")
{
    SECTION("if it is divisible by 4 but not 100")
    {
        REQUIRE(is_leap_year(1984));
    }
    SECTION("if it is divisible by 400")
    {
        REQUIRE(is_leap_year(2000));
    }
}
