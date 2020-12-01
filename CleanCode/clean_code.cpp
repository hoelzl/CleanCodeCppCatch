#include "complex_function.h"
#include <iostream>
#include <string>

void f1(int x)
{
    std::cout << "x = " << x;
}

int f2(int x, int y)
{
    int result = x + y;
    std::cout << "z1 = " << result << std::endl;
    return result;
}

int f3(int y, int z1)
{
    int z2 = y + z1;
    std::cout << "z2 = " << z2 << std::endl;
    return z2;
}

int long_function(int x, int y)
{
    f1(x);
    int z1 = f2(x, y);
    int z2 = f3(x, y);

    int z3 = z1 + z2;
    std::cout << "z3 = " << z3 << std::endl;
    return 1;
}

int main()
{
    std::string formatted_text(format_text("This is the text to format\n",
                                           "<<< A header >>>\n",
                                           "<<< A footer >>>\n", 10));
    std::cout << "Original output:" << std::endl;
    std::cout << formatted_text << std::endl;

    FormatText format_text_object(
            "This is the text to format with the object\n",
            "<<< A header >>>\n", "<<< A footer >>>\n", 10);
    formatted_text = format_text_object.compute();

    std::cout << "Output of compute():" << std::endl;
    std::cout << formatted_text << std::endl;

    //// Careful!
    //// This does not produce the expected result!
    formatted_text = format_text_object.compute();

    formatted_text = FormatText("This is the text to format\n",
                                "<<< A header >>>\n", "<<< A footer >>>\n", 10).compute();

    std::cout << "Output of string conversion:" << std::endl;
    std::cout << formatted_text << std::endl;

    std::cout << "The end.";
}