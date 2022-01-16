#include <string>

using std::string;

string format_text(string text, string header, string footer,
                   std::size_t num_separator_chars)
{
    std::size_t min_num_separator_chars(6);
    bool include_headers(num_separator_chars > min_num_separator_chars);
    string separator(static_cast<char>(num_separator_chars), '=');
    string result;

    if (include_headers) {
        result += header;
    }
    result += text;
    result += footer;

    return result;
}
