#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "prime_factors.h"
#include <functional>
#include <numeric>
#include <vector>

TEST_CASE("compute_prime_factors(2) returns [2]")
{
    std::vector<long> expected { 2L };

    REQUIRE(compute_prime_factors(2L) == expected);
}

TEST_CASE("compute_prime_factors(3) returns [3]")
{
    std::vector<long> expected { 3L };

    REQUIRE(compute_prime_factors(3L) == expected);
}

TEST_CASE("compute_prime_factors(4) returns [2, 2]")
{
    std::vector<long> expected { 2L, 2L };

    REQUIRE(compute_prime_factors(4L) == expected);
}

TEST_CASE("compute_prime_factors(5) returns [5]")
{
    std::vector<long> expected { 5L };

    REQUIRE(compute_prime_factors(5L) == expected);
}

bool is_prime(long n)
{
    for (long factor = 2; factor < n; ++factor) {
        if (n % factor == 0) {
            return false;
        }
    }
    return true;
}

long multiply_elements(const std::vector<long>& v)
{
    return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
}

// Try the tag combinations [!hide][slow] (or [.slow]) to exclude the
// test from default runs.
TEST_CASE("Pseudo-parametric/property-based test case", "[slow]")
{
    for (long i = 1; i < 1000L; ++i) {
        std::vector<long> result = compute_prime_factors(i);
        REQUIRE(multiply_elements(result) == i);
        for (long n : result) {
            REQUIRE(is_prime(n));
        }
    }
}