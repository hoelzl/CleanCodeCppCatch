#include <catch2/catch_test_macros.hpp>

bool is_leap_year(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

TEST_CASE("A year is a leap year")
{
    // clang-format off
    SECTION("if it is divisible by 4 and not 100") {
        CHECK(is_leap_year(1984));
    }

    SECTION("if it is divisible by 400") {
        CHECK(is_leap_year(2000));
    }
    // clang-format on
}

TEST_CASE("A year is not a leap year")
{
    // clang-format off
    SECTION("if it is not divisible by 4") {
        CHECK_FALSE(is_leap_year(2022));
    }

    SECTION("if it is divisible by 100") {
        CHECK_FALSE(is_leap_year(1900));
    }
    // clang-format on
}
