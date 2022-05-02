// Copyright (c) 2022 Dr. Matthias Hölzl.

#include "complex_function.hpp"

#include <iostream>

const std::string test_text{"This is the test_text to format\n"};
const std::string test_header{"<<< A test_header >>>\n"};
const std::string test_footer{"<<< A test_footer >>>\n"};

std::string format_text(
    const std::string& text, const std::string& header, const std::string& footer,
    std::size_t num_separator_chars)
{
    constexpr std::size_t min_num_separator_chars(6);
    const bool include_headers(num_separator_chars > min_num_separator_chars);
    std::string separator(static_cast<char>(num_separator_chars), '=');
    std::string result;

    if (include_headers) {
        result += header;
    }
    result += text;
    result += footer;

    return result;
}

void format_text_with_original_function()
{
    std::cout << "Original output:" << '\n';
    std::cout << std::string{format_text(test_text, test_header, test_footer, 10)}
              << '\n';
}
