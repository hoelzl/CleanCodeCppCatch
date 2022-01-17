#include <iostream>

#include "stack.h"

int main()
{
    Stack stack{};
    stack.push(1);
    stack.push(2);
    std::cout << "Stack size is " << stack.size() << std::endl;
}
