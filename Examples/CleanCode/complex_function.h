#pragma once
#include <string>

std::string format_text(std::string text, std::string header,
                        std::string footer, std::size_t num_separator_chars);

class FormatText
{
    std::string text;
    std::string header;
    std::string footer;
    std::size_t num_separator_chars;
    std::size_t min_num_separator_chars{6};
    bool include_headers{};
    std::string separator{static_cast<char>(num_separator_chars), '='};
    std::string result{};

public:
    FormatText(std::string text, std::string header, std::string footer,
               std::size_t num_separator_chars)
        : text{text}, header{header}, footer{footer},
          num_separator_chars{num_separator_chars}
    {
    }

    std::string compute()
    {
        result = "";

        add_header();
        result += text;
        add_footer();

        return result;
    }

private:
    void add_header()
    {
        include_headers = num_separator_chars > min_num_separator_chars;

        if (include_headers) {
            result += header;
        }
    }

    void add_footer()
    {
        result += footer;
    }
};


// Refactored to class
//class FormatText
//{
//    std::string text;
//    std::string header;
//    std::string footer;
//    std::size_t num_separator_chars;
//    std::size_t min_num_separator_chars = 6;
//    bool include_headers = num_separator_chars > min_num_separator_chars;
//    std::string separator =
//            std::string(static_cast<char>(num_separator_chars), '=');
//    std::string result{};
//
//public:
//    FormatText(std::string text, std::string header, std::string footer,
//               std::size_t num_separator_chars)
//        : text(text), header(header), footer(footer),
//          num_separator_chars(num_separator_chars)
//    {
//    }
//
//    std::string compute()
//    {
//        compute_header();
//        compute_text();
//        compute_footer();
//
//        return result;
//    }
//
//    void compute_footer()
//    {
//        result += footer;
//    }
//
//    void compute_text()
//    {
//        result += text;
//    }
//
//    void compute_header()
//    {
//        if (include_headers) {
//            result += header;
//        }
//    }
//};


// Intermediate step
//class FormatText
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
//public:
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
