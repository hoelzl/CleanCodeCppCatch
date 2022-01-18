#include <iostream>
#include <string>

#include "prime_factors.h"

int main(int argc, char** argv) {

    const int number_to_factor{argc >= 2 ? std::stoi(argv[1]) : 100};
    std::cout << "I don't know how to factor, yet.\n" << "Please fix me.\n";
}
