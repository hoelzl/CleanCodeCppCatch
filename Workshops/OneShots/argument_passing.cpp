#include <array>
#include <catch2/catch_test_macros.hpp>
#include <gsl/gsl>
#include <numeric>

int fun1(const int& my_int, const int* your_int) { return 2 * my_int + 3 * *your_int; }

TEST_CASE("fun1()")
{
    constexpr int i{2};
    CHECK(fun1(1, &i) == 8);
}

int fun2(std::array<int, 1024> values)
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

void fun3(SomeStruct* s)
{
    const int tmp{s->x + s->y};
    s->y = s->x;
    s->x = tmp;
}

TEST_CASE("fun3()")
{
    SomeStruct s{3, 2};
    fun3(&s);
    CHECK(s.x == 5);
    CHECK(s.y == 3);
}

void fun4(int x, int y, int& res) { res = x + y; }

TEST_CASE("fun4()")
{
    int result{0};
    fun4(2, 3, result);
    CHECK(result == 5);
}

void fun5(int x, int y, int& sum, int& prod)
{
    sum = x + y;
    prod = x * y;
}

TEST_CASE("fun5()")
{
    int sum{0};
    int prod{0};
    fun5(2, 3, sum, prod);
    CHECK(sum == 5);
    CHECK(prod == 6);
}

int fun6(const SomeStruct& s, bool is_valid)
{
    if (!is_valid) {
        return -1;
    }
    return s.x + s.y;
}

TEST_CASE("fun6()")
{
    constexpr SomeStruct s{2, 3};
    CHECK(fun6(s, false) == -1);
    CHECK(fun6(s, true) == 5);
}
