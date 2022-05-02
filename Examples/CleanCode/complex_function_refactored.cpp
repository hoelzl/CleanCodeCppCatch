#include "complex_function_refactored.hpp"

#include <iostream>

void format_text_after_refactoring()
{
    FormatText format_text_object{test_text, test_header, test_footer, 10};

    std::string formatted_text{format_text_object.compute()};
    std::cout << "Output of compute():" << '\n';
    std::cout << formatted_text << '\n';

    //// Careful!
    //// This does not produce the expected result!
    formatted_text = format_text_object.compute();
    std::cout << "Output of second call to compute():" << '\n';
    std::cout << formatted_text << '\n';
}

void format_text_with_refactored_function_inline()
{
    std::cout << "Output of inline construction:" << '\n';
    std::cout << FormatText{test_text, test_header, test_footer, 10}.compute()
              << "\n\n";
}
