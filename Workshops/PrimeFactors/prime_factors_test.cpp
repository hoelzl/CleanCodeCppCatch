#include "prime_factors.h"

#include <catch2/catch_test_macros.hpp>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>

using namespace prime_factors;
using namespace std::string_literals;

TEST_CASE("compute_prime_factors()")
{
    SECTION("compute_prime_factors(2) returns [2]")
    {
        std::vector<long> expected{{2L}};
        CHECK(compute_prime_factors(2L) == expected);
    }

    SECTION("compute_prime_factors(3) returns [3]")
    {
        std::vector<long> expected{{3L}};
        CHECK(compute_prime_factors(3L) == expected);
    }

    SECTION("compute_prime_factors(4) returns [2, 2]")
    {
        std::vector<long> expected{{2L, 2L}};
        CHECK(compute_prime_factors(4L) == expected);
    }

    SECTION("compute_prime_factors(5) returns [5]")
    {
        std::vector<long> expected{{5L}};
        CHECK(compute_prime_factors(5L) == expected);
    }
}

bool is_prime(long n)
{
    for (long factor{2}; factor < n; ++factor) {
        if (n % factor == 0) {
            return false;
        }
    }
    return true;
}

long multiply_elements(const std::vector<long>& primes)
{
    return std::accumulate(primes.cbegin(), primes.cend(), 1L, std::multiplies<>());
}

TEST_CASE("Property-based test for compute_prime_factors()", "[.][slow]")
{
    for (long i{1}; i < 1'000L; ++i) {
        // Check that compute_prime_factors(i) is the correct solution
        std::vector<long> result{compute_prime_factors(i)};
        CHECK(multiply_elements(result) == i);
        CHECK(std::is_sorted(result.cbegin(), result.cend()));

        for (const long n : result) {
            CHECK(is_prime(n));
        }
    }
}

TEST_CASE("format_primes()")
{
    SECTION("Format an empty vector of primes") {
        CHECK(format_primes(std::vector<long>{}) == ""s);
    }

    SECTION("Format a vector with one element") {
        const std::vector<long> unit{2L};
        std::string expected{"2"};
        CHECK(format_primes(unit) == expected);
    }

    SECTION("Format a vector with two elements correctly") {
        const std::vector<long> unit{2L, 5L};
        std::string expected{"2, 5"};
        CHECK(format_primes(unit) == expected);
    }
    
    SECTION("Format a vector with two elements correctly") {
        const std::vector<long> unit{2L, 5L, 5L, 7L};
        std::string expected{"2, 5, 5, 7"};
        CHECK(format_primes(unit) == expected);
    }
}

TEST_CASE("compute_and_write_primes()")
{
    SECTION("Print the correct output for 2") {
        const std::string expected{"The primes of 2 are 2"};
        std::ostringstream os{};
        compute_and_write_primes(2L, os);
        CHECK(os.str() == expected);
    }

    SECTION("Print the correct output for 100") {
        const std::string expected{"The primes of 100 are 2, 2, 5, 5"};
        std::ostringstream os{};
        compute_and_write_primes(100L, os);
        CHECK(os.str() == expected);
    }
}
