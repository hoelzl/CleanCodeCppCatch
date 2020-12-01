#include "complex_function.h"
#include <iostream>
#include <string>

int main()
{
    std::string formatted_text(format_text(
        "This is the text to format\n",
        "<<< A header >>>\n",
        "<<< A footer >>>\n",
        10));
    std::cout << "Original output:" << std::endl;
    std::cout << formatted_text << std::endl;

    FormatText format_text_object(
        "This is the text to format with the object\n",
        "<<< A header >>>\n",
        "<<< A footer >>>\n",
        10);

    formatted_text = format_text_object.compute();

    std::cout << "Output of compute():" << std::endl;
    std::cout << formatted_text << std::endl;

    // Careful!
    // This does not produce the expected result!
    // formatted_text = format_text_object;
    formatted_text = FormatText(
        "This is the text to format\n",
        "<<< A header >>>\n",
        "<<< A footer >>>\n",
        10);

    std::cout << "Output of string conversion:" << std::endl;
    std::cout << formatted_text << std::endl;

    std::cout << "The end.";
}