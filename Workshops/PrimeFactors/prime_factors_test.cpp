#include "prime_factors.h"

#include <catch2/catch_test_macros.hpp>

using namespace prime_factors;

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
}
