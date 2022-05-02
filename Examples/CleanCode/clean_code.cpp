// Copyright (c) 2022 Dr. Matthias Hölzl.

// ReSharper disable CppClangTidyBugproneExceptionEscape
#include <iostream>

#include "complex_function.hpp"
#include "complex_function_refactored.hpp"
#include "functions.hpp"
#include "classes.hpp"

int main()
{
    test_print_text_using_struct();
    std::cout << '\n';

    test_refactoring_into_classes();
    std::cout << '\n';

    format_text_with_original_function();
    format_text_after_refactoring();

    format_text_with_refactored_function_inline();

    test_employee_with_switch();
    std::cout << '\n';
    test_employee();
}
