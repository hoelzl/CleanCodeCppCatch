#include <iostream>

#include "prime_factors.h"

int main(int argc, char** argv)
{
    const int number_to_factor{argc >= 2 ? std::stol(argv[1]) : 100L};
    compute_and_write_primes(number_to_factor, std::cout);
}
