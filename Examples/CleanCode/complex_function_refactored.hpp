// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef COMPLEX_FUNCTION_REFACTORED_H
#define COMPLEX_FUNCTION_REFACTORED_H

#include "complex_function.hpp"

//
// Start:
// class FormatText
//{
//    // ReSharper disable once CppMemberFunctionMayBeStatic
//    std::string compute(
//        const std::string& test_text, const std::string& test_header, const std::string& test_footer,
//        std::size_t num_separator_chars)
//    {
//        // Beware of the most vexing parse! Use uniform initialization instead of parens.
//        constexpr std::size_t min_num_separator_chars{6};
//        const bool include_headers{num_separator_chars > min_num_separator_chars};
//        std::string separator{static_cast<char>(num_separator_chars), '='};
//        std::string result{};
//
//        if (include_headers) {
//            result += test_header;
//        }
//        result += test_text;
//        result += test_footer;
//
//        return result;
//    }
//};

// Intermediate step
// class FormatText
//{
//    std::string test_text{};
//    std::string test_header{};
//    std::string test_footer{};
//    // Beware of the most vexing parse!
//    std::size_t num_separator_chars{};
//    std::size_t min_num_separator_chars{6};
//    bool include_headers{num_separator_chars > min_num_separator_chars};
//    std::string separator{std::string(static_cast<char>(num_separator_chars), '=')};
//    std::string result{};
//
// public:
//    FormatText(std::string test_text, std::string test_header, std::string test_footer,
//               std::size_t num_separator_chars)
//        : test_text(test_text), test_header(test_header), test_footer(test_footer),
//          num_separator_chars(num_separator_chars)
//    {
//    }
//
//    std::string compute()
//    {
//        if (include_headers) {
//            result += test_header;
//        }
//        result += test_text;
//        result += test_footer;
//
//        return result;
//    }
//
//    operator std::string()
//    {
//        return this->compute();
//    }
//};


// Refactored to class
class FormatText
{
    std::string text{};
    std::string header{};
    std::string footer{};
    std::size_t num_separator_chars{};
    // Beware of the most vexing parse!
    std::size_t min_num_separator_chars{6};
    bool include_headers{num_separator_chars > min_num_separator_chars};
    std::string separator{std::string(static_cast<char>(num_separator_chars), '=')};
    std::string result{};

public:
    FormatText(
        std::string text, std::string header, std::string footer,
        std::size_t num_separator_chars);

    std::string compute()
    {
        compute_header();
        compute_text();
        compute_footer();

        return result;
    }

    void compute_footer() { result += footer; }

    void compute_text() { result += text; }

    void compute_header()
    {
        if (include_headers) {
            result += header;
        }
    }
};

inline FormatText::FormatText(
    std::string text, std::string header, std::string footer,
    std::size_t num_separator_chars)
    : text(std::move(text))
    , header(std::move(header))
    , footer(std::move(footer))
    , num_separator_chars(num_separator_chars)
{}


void format_text_after_refactoring();
void format_text_with_refactored_function_inline();


#endif // COMPLEX_FUNCTION_REFACTORED_H
