// Copyright (c) 2022 Dr. Matthias Hölzl.

#pragma once
#ifndef COMPLEX_FUNCTION_REFACTORED_H
#define COMPLEX_FUNCTION_REFACTORED_H

//
// Start:
// class FormatText
//{
//    // ReSharper disable once CppMemberFunctionMayBeStatic
//    std::string compute(
//        const std::string& text, const std::string& header, const std::string& footer,
//        std::size_t num_separator_chars)
//    {
//        constexpr std::size_t min_num_separator_chars(6);
//        const bool include_headers(num_separator_chars > min_num_separator_chars);
//        std::string separator(static_cast<char>(num_separator_chars), '=');
//        std::string result;
//
//        if (include_headers) {
//            result += header;
//        }
//        result += text;
//        result += footer;
//
//        return result;
//    }
//};

// Intermediate step
// class FormatText
//{
//    std::string text;
//    std::string header;
//    std::string footer;
//    std::size_t num_separator_chars;
//    std::size_t min_num_separator_chars = 6;
//    bool include_headers = num_separator_chars > min_num_separator_chars;
//    std::string separator =
//            std::string(static_cast<char>(num_separator_chars), '=');
//    std::string result = "";
//
// public:
//    FormatText(std::string text, std::string header, std::string footer,
//               std::size_t num_separator_chars)
//        : text(text), header(header), footer(footer),
//          num_separator_chars(num_separator_chars)
//    {
//    }
//
//    std::string compute()
//    {
//        if (include_headers) {
//            result += header;
//        }
//        result += text;
//        result += footer;
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
    std::string text;
    std::string header;
    std::string footer;
    std::size_t num_separator_chars;
    std::size_t min_num_separator_chars = 6;
    bool include_headers = num_separator_chars > min_num_separator_chars;
    std::string separator = std::string(static_cast<char>(num_separator_chars), '=');
    std::string result{};

public:
    FormatText(
        std::string text, std::string header, std::string footer,
        std::size_t num_separator_chars)
        : text(text)
        , header(header)
        , footer(footer)
        , num_separator_chars(num_separator_chars)
    {}

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


#endif // COMPLEX_FUNCTION_REFACTORED_H