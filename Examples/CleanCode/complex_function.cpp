#include <string>

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
