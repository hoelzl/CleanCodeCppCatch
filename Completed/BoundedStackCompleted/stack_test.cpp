// ReSharper disable CppClangTidyCppcoreguidelinesMacroUsage

#include <catch2/catch_test_macros.hpp>

#include "simple_bounded_stack.h"

constexpr int an_arbitrary_number{17};
constexpr int another_arbitrary_number{34};
constexpr int a_third_arbitrary_number{49};

SCENARIO("Tests for core stack functionality")
{
    GIVEN("a newly constructed stack")
    {
        Stack stack{};

        WHEN("nothing has been pushed")
        {
            THEN("the stack is empty") { CHECK(stack.is_empty()); }
            THEN("its size is 0") { CHECK(stack.size() == 0); }
            THEN("pop throws an exception")
            {
                CHECK_THROWS_AS(stack.pop(), std::out_of_range);
            }
        }

        WHEN("a single element has been pushed")
        {
            stack.push(an_arbitrary_number);

            THEN("the stack is no longer empty") { CHECK_FALSE(stack.is_empty()); }
            THEN("its size is 1") { CHECK(stack.size() == 1); }
            THEN("pop returns this value")
            {
                int popped_value = stack.pop();

                CHECK(popped_value == an_arbitrary_number);

                AND_THEN("removes it from the stack") { CHECK(stack.is_empty()); }
            }
        }

        WHEN("three elements are pushed")
        {
            stack.push(an_arbitrary_number);
            stack.push(another_arbitrary_number);
            stack.push(a_third_arbitrary_number);

            THEN("the stack has size 3") { CHECK(stack.size() == 3); }
            THEN("pop takes the topmost element")
            {
                int popped_value = stack.pop();

                CHECK(popped_value == a_third_arbitrary_number);

                AND_THEN("the resulting stack has size 2") { CHECK(stack.size() == 2); }
            }
        }
    }
}
SCENARIO("Tests for bounded stacks")
{
    GIVEN("a bounded stack")
    {
        Stack stack;

        WHEN("the stack is full")
        {
            for (int i = 0; i < Stack::max_size; ++i) {
                stack.push(an_arbitrary_number);
            }

            THEN("is_full returns true") { CHECK(stack.is_full()); }
            THEN("push throws an exception")
            {
                CHECK_THROWS_AS(
                    stack.push(another_arbitrary_number), std::out_of_range);
            }
        }

        WHEN("the stack is empty")
        {
            THEN("is_full returns false") { CHECK_FALSE(stack.is_full()); }
            THEN("is_empty returns true") { CHECK(stack.is_empty()); }
            THEN("push succeeds") { CHECK_NOTHROW(stack.push(an_arbitrary_number)); }
        }
    }
}
