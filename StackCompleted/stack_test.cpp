#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stack.h"

int an_arbitrary_number{17};
int another_arbitrary_number{34};
int a_third_arbitrary_number{49};
int a_fourth_arbitrary_number{75};

#define USE_BOUNDED_STACK_TYPE 0

#ifdef USE_BOUNDED_STACK_TYPE
using Stack_t = BoundedStack;
#else
using Stack_t = Stack;
#endif// USE_BOUNDED_STACK_TYPE


SCENARIO("Tests for core stack functionality")
{
    GIVEN("a newly constructed stack")
    {
        Stack_t stack{};

        WHEN("nothing has been pushed")
        {
            THEN("the stack is empty")
            {
                REQUIRE(stack.is_empty());
            }
            THEN("its size is 0")
            {
                REQUIRE(stack.size() == 0);
            }
            THEN("pop throws an exception")
            {
                REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
            }
            THEN("pop_default returns the default value")
            {
                REQUIRE(stack.pop_default(an_arbitrary_number) ==
                        an_arbitrary_number);
            }
        }

        WHEN("a single element has been pushed")
        {
            stack.push(an_arbitrary_number);

            THEN("the stack is no longer empty")
            {
                REQUIRE_FALSE(stack.is_empty());
            }
            THEN("its size is 1")
            {
                REQUIRE(stack.size() == 1);
            }
            THEN("pop returns this value")
            {
                int popped_value = stack.pop();
                REQUIRE(popped_value == an_arbitrary_number);

                AND_THEN("removes it from the stack")
                {
                    REQUIRE(stack.is_empty());
                }
            }
            THEN("pop_default returns this value")
            {
                int popped_value = stack.pop_default(another_arbitrary_number);
                REQUIRE(popped_value == an_arbitrary_number);

                AND_THEN("removes it from the stack")
                {
                    REQUIRE(stack.is_empty());
                }
            }
        }

        WHEN("three elements are pushed")
        {
            stack.push(an_arbitrary_number);
            stack.push(another_arbitrary_number);
            stack.push(a_third_arbitrary_number);

            THEN("the stack has size 3")
            {
                REQUIRE(stack.size() == 3);
            }
            THEN("pop takes the topmost element")
            {
                int popped_value = stack.pop();
                REQUIRE(popped_value == a_third_arbitrary_number);

                AND_THEN("the resulting stack has size 2")
                {
                    REQUIRE(stack.size() == 2);
                }
            }
            THEN("pop_default takes the topmost element")
            {
                int popped_value = stack.pop_default(a_fourth_arbitrary_number);
                REQUIRE(popped_value == a_third_arbitrary_number);

                AND_THEN("the resulting stack has size 2")
                {
                    REQUIRE(stack.size() == 2);
                }
            }
        }
    }

    GIVEN("a newly constructed stack with default value")
    {
        Stack_t stack{};
        stack.set_default(an_arbitrary_number);

        WHEN("nothing has been pushed")
        {
            THEN("the stack is empty")
            {
                REQUIRE(stack.is_empty());
            }
            THEN("its size is 0")
            {
                REQUIRE(stack.size() == 0);
            }
            THEN("pop returns the default value")
            {
                REQUIRE(stack.pop() == an_arbitrary_number);
            }
            THEN("pop_default returns its own default value")
            {
                REQUIRE(stack.pop_default(another_arbitrary_number) ==
                        another_arbitrary_number);
            }
        }

        WHEN("a single element has been pushed")
        {
            stack.push(another_arbitrary_number);

            THEN("the stack is no longer empty")
            {
                REQUIRE_FALSE(stack.is_empty());
            }
            THEN("its size is 1")
            {
                REQUIRE(stack.size() == 1);
            }
            THEN("pop returns the pushed value")
            {
                int popped_value = stack.pop();
                REQUIRE(popped_value == another_arbitrary_number);

                AND_THEN("removes it from the stack")
                {
                    REQUIRE(stack.is_empty());
                }
            }
            THEN("pop_default returns the pushed value")
            {
                int popped_value = stack.pop_default(a_third_arbitrary_number);
                REQUIRE(popped_value == another_arbitrary_number);

                AND_THEN("removes it from the stack")
                {
                    REQUIRE(stack.is_empty());
                }
            }
        }

        WHEN("the default value is cleared")
        {
            stack.clear_default();

            THEN("the stack is empty")
            {
                REQUIRE(stack.is_empty());
            }
            THEN("pop throws an exception")
            {
                REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
            }
            THEN("pop_default returns its argument value")
            {
                REQUIRE(stack.pop_default(another_arbitrary_number) ==
                        another_arbitrary_number);
            }
        }
    }
}

SCENARIO("Tests for counting elements")
{
    Stack_t stack{};

    GIVEN("an empty stack")
    {
        THEN("count returns 0")
        {
            REQUIRE(stack.count(an_arbitrary_number) == 0);
        }
    }

    GIVEN("a stack with several elements")
    {
        stack.push(an_arbitrary_number);
        stack.push(another_arbitrary_number);
        stack.push(a_third_arbitrary_number);
        stack.push(an_arbitrary_number);

        WHEN("an element is not on the stack")
        {
            THEN("count returns 0")
            {
                REQUIRE(stack.count(a_fourth_arbitrary_number) == 0);
            }
        }
        WHEN("an element is on the stack")
        {
            THEN("count returns the number of occurrences on the stack")
            {
                REQUIRE(stack.count(an_arbitrary_number) == 2);
                REQUIRE(stack.count(another_arbitrary_number) == 1);
                REQUIRE(stack.count(a_third_arbitrary_number) == 1);
            }
        }
        WHEN("an element has been popped off")
        {
            stack.pop();
            stack.pop();

            THEN("count no longer counts the popped occurrences")
            {
                REQUIRE(stack.count(an_arbitrary_number) == 1);
                REQUIRE(stack.count(a_third_arbitrary_number) == 0);
            }
            THEN("the count of other elements is not affected")
            {
                REQUIRE(stack.count(another_arbitrary_number) == 1);
            }
        }
    }
}

SCENARIO("Tests for bounded stacks")
{
    GIVEN("a bounded stack")
    {
        Stack_t stack;

        WHEN("the stack is full")
        {
            for (int i = 0; i < Stack_t::max_size; ++i) {
                stack.push(an_arbitrary_number);
            }

            THEN("is_full returns true")
            {
                REQUIRE(stack.is_full());
            }
            THEN("push throws an exception")
            {
                REQUIRE_THROWS_AS(stack.push(another_arbitrary_number),
                                  std::out_of_range);
            }
        }

        WHEN("the stack is empty")
        {
            THEN("is_full returns false")
            {
                REQUIRE_FALSE(stack.is_full());
            }
            THEN("is_empty returns true")
            {
                REQUIRE(stack.is_empty());
            }
            THEN("push succeeds")
            {
                REQUIRE_NOTHROW(stack.push(an_arbitrary_number));
            }
        }
    }
}
