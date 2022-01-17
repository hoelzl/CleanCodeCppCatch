#pragma once
#include <string>

std::string format_text(
    const std::string& text, const std::string& header, const std::string& footer,
    std::size_t num_separator_chars);

// Use refactoring into a class to disentangle this function!
