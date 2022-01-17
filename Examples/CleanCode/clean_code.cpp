// ReSharper disable CppClangTidyBugproneExceptionEscape
#include <iostream>
#include <string>

#include "complex_function.h"
#include "complex_function_refactored.h"


void format_text_example()
{
    std::string formatted_text{format_text(
        "This is the text to format\n", "<<< A header >>>\n", "<<< A footer >>>\n",
        10)};
    std::cout << "Original output:" << std::endl;
    std::cout << formatted_text << std::endl;

    FormatText format_text_object{
        "This is the text to format with the object\n", "<<< A header >>>\n",
        "<<< A footer >>>\n", 10};
    formatted_text = format_text_object.compute();

    std::cout << "Output of compute():" << std::endl;
    std::cout << formatted_text << std::endl;

    //// Careful!
    //// This does not produce the expected result!
    formatted_text = format_text_object.compute();

    std::cout << "Output of second call to compute():" << std::endl;
    std::cout << formatted_text << std::endl;

    formatted_text
        = FormatText{"This is the text to format\n", "<<< A header >>>\n", "<<< A footer >>>\n", 10}
              .compute();

    std::cout << "Output of inline construction:" << std::endl;
    std::cout << formatted_text << std::endl;

    std::cout << "The end.";
}

int main() { format_text_example(); }
