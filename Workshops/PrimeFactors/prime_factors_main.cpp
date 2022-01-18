#include <iostream>
#include <string>

#include "prime_factors.h"

int main(int argc, char** argv) {
    const long number_to_factor{argc >= 2 ? std::stol(argv[1]) : 100L};
    prime_factors::compute_and_write_primes(number_to_factor, std::cout);
}
