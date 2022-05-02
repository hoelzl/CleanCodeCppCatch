// Copyright (c) 2022 Dr. Matthias Hölzl.

// ReSharper disable CppClangTidyCppcoreguidelinesAvoidCArrays

#include "functions.hpp"

#include <iostream>


// Functions

// Not intention revealing, could be expressed in code
void copy(char a1[], char a2[])
{
    while ((*(a2++) = *(a1++))) {}
}

// Better names, but does not express intention in code
void copy_2(char from[], char to[])
{
    while ((*(to++) = *(from++))) {}
}

// Still better, expresses constness of first argument
void copy_3(const char from[], char to[])
{
    while ((*(to++) = *(from++))) {}
}

// Even better...
void copy_4(std::string from, std::string& to) { to = std::move(from); }

// ... but it would be best to completely remove the need for these kinds of
// functions in the code.


// Long argument lists
void my_long_arglist_function(int a, int b, int c) {}
void my_long_arglist_function_2(float x, int a, int b, int c) {}

struct GridPosition
{
    int a;
    int b;
    int c;
};

void my_long_arglist_function(GridPosition g) {}
void my_long_arglist_function_2(float x, GridPosition g) {}

// Boolean parameters
void print_text(const std::string& text, bool should_print_header = false)
{
    if (should_print_header) {
        std::cout << "Header\n";
    }
    // The call to .c_str() is necessary to work around a missing operator<<() in
    // VS2017.
    std::cout << text.c_str() << '\n';
}

void print_text_without_header(const std::string& text)
{
    std::cout << text.c_str() << '\n';
}

void print_text_with_header(const std::string& text)
{
    std::cout << "Header\n";
    std::cout << text.c_str() << '\n';
}

enum class TextDecoration
{
    none,
    header,
};

void print_text_using_enum(
    const std::string& text, TextDecoration decoration = TextDecoration::none)
{
    if (decoration == TextDecoration::header) {
        std::cout << "Header\n";
    }
    std::cout << text.c_str() << '\n';
}

enum class TextDecoration2
{
    none,
    header_only,
    footer_only,
    header_and_footer,
};

void print_text_using_enum2(
    const std::string& text, TextDecoration2 decoration = TextDecoration2::none)
{
    if (decoration == TextDecoration2::header_only
        || decoration == TextDecoration2::header_and_footer) {
        std::cout << "Header\n";
    }

    std::cout << text.c_str() << '\n';

    if (decoration == TextDecoration2::footer_only
        || decoration == TextDecoration2::header_and_footer) {
        std::cout << "Footer\n";
    }
}

struct PrinterConfig
{
    bool include_header{false};
    bool include_footer{false};
    int indent{4};
};

void print_text_using_struct(const std::string& text, PrinterConfig config = {})
{
    if (config.include_header) {
        std::cout << "Header\n";
    }

    std::cout << text.c_str() << '\n';

    if (config.include_footer) {
        std::cout << "Footer\n";
    }
}

void test_print_text_using_struct()
{
    print_text_using_struct("Foo!");
    std::cout << '\n';
#if (__cplusplus >= 202002L)
    print_text_using_struct("Foo!", {.include_header = true});
    std::cout << '\n';
    print_text_using_struct("Foo!", {.include_footer = true});
    std::cout << '\n';
    print_text_using_struct(
        "Foo!", {.include_header = true, .include_footer = true, .indent = 2});
#else
    print_text_using_struct("Foo!", {true});
    std::cout << '\n';
    print_text_using_struct("Foo!", {false, true});
    std::cout << '\n';
    print_text_using_struct("Foo!", {true, true, 2});
#endif
}


// Refactoring into classes
int my_fun(int a, int b)
{
    // Do something complex
    int c{a + b};
    ++c;
    // Work some more
    int d{0};
    d += c;
    // Do something else
    c *= d;
    return c;
}

class MyFun
{
    int a;
    int b;
    int c{a + b};
    int d{0};

public:
    MyFun(int a, int b) : a{a}, b{b} {}

    void do_something_complex() { ++c; }
    void work_some_more() { d += c; }
    void do_something_else() { c *= d; }

    int compute()
    {
        do_something_complex();
        work_some_more();
        do_something_else();
        return c;
    }
};

void test_refactoring_into_classes()
{
    const int i{my_fun(1, 2)};

    MyFun my_refactored_fun{1, 2};
    const int j{my_refactored_fun.compute()};

    if (i == j) {
        std::cout << "Refactoring into classes worked.\n";
    }
    else {
        std::cout << "Refactoring into classes DID NOT work.\n";
    }
}
