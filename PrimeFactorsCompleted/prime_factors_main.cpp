#include "prime_factors.h"

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    int max_number { argc >= 2 ? std::stol(argv[1]) : 100 };
    std::vector<long> primes { compute_prime_factors(max_number) };

    std::cout << "The primes up to " << max_number << " are: ";
    std::string prefix { "[" };

    for (int prime : primes) {
        std::cout << prefix << prime;
        prefix = ", ";
    }

    std::cout << "]" << std::endl;
}