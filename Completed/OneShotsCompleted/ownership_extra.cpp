#include <catch2/catch_test_macros.hpp>

int compute_pointer_sum(const int* x, const int* y)
{
    return *x + *y;
}

TEST_CASE("compute_pointer_sum()")
{
    constexpr int x{2};
    constexpr int y{3};
    CHECK(compute_pointer_sum(&x, &y) == 5);
}

int compute_reference_sum(const int& x, const int& y)
{
    return x + y;
}

TEST_CASE("compute_reference_sum()")
{
    constexpr int x{2};
    constexpr int y{3};
    CHECK(compute_reference_sum(x, y) == 5);
}

int compute_reference_sum_and_mutate(int& x, int& y)
{
    const auto result{x + y};
    ++x;
    y += 30;
    return result;
}

TEST_CASE("compute_reference_sum_and_mutate()")
{
    int x{2};
    int y{3};
    CHECK(compute_reference_sum_and_mutate(x, y) == 5);
    CHECK(x == 3);
    CHECK(y == 33);
}
