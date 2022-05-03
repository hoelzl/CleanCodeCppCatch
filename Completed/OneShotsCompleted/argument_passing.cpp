#include <array>
#include <catch2/catch_test_macros.hpp>
#include <gsl/gsl>
#include <numeric>

namespace argument_passing {

int fun1(int my_int, int your_int);

int fun1(const int my_int, const int your_int) { return 2 * my_int + 3 * your_int; }

TEST_CASE("fun1()")
{
    constexpr int i{2};
    CHECK(fun1(1, i) == 8);
}


int fun2(const std::array<int, 1024>& values)
{
    return std::accumulate(values.cbegin(), values.cend(), 0);
}

TEST_CASE("fun2()")
{
    std::array<int, 1024> my_values{};
    std::iota(my_values.begin(), my_values.end(), 1);
    CHECK(fun2(my_values) == 524'800);
}

struct SomeStruct
{
    int x;
    int y;
};

void fun3(SomeStruct& s)
{
    const int tmp{s.x + s.y};
    s.y = s.x;
    s.x = tmp;
}

TEST_CASE("fun3()")
{
    SomeStruct s{3, 2};
    fun3(s);
    CHECK(s.x == 5);
    CHECK(s.y == 3);
}

int fun4(int x, int y) { return x + y; }

TEST_CASE("fun4()")
{
    const int result{fun4(2, 3)};
    CHECK(result == 5);
}

std::pair<int, int> fun5(int x, int y) { return {x + y, x * y}; }

TEST_CASE("fun5()")
{
    const auto [sum, prod]{fun5(2, 3)};
    CHECK(sum == 5);
    CHECK(prod == 6);
}

struct SumProd
{
    int sum{};
    int prod{};
};

SumProd fun5_a(int x, int y) { return {x + y, x * y}; }

TEST_CASE("fun5a()")
{
    const auto [sum, prod]{fun5_a(2, 3)};
    CHECK(sum == 5);
    CHECK(prod == 6);
}

int fun6(const SomeStruct* s)
{
    if (!s) {
        return -1;
    }
    return s->x + s->y;
}

TEST_CASE("fun6()")
{
    constexpr SomeStruct s{2, 3};
    CHECK(fun6(nullptr) == -1);
    CHECK(fun6(&s) == 5);
}

} // namespace argument_passing
