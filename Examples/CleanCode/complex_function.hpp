#pragma once
#include <string>

std::string format_text(
    const std::string& text, const std::string& header, const std::string& footer,
    std::size_t num_separator_chars);

// Use refactoring into a class to disentangle this function!

extern const std::string test_text;
extern const std::string test_header;
extern const std::string test_footer;

void format_text_with_original_function();