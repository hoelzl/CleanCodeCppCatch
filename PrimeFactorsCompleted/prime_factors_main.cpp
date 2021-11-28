#include "prime_factors.h"

#include <iostream>
#include <string>

void print_primes(const std::vector<long>& primes);

int main(int argc, char** argv)
{
    int number_to_factor{argc >= 2 ? std::stol(argv[1]) : 100};
    std::vector<long> prime_factors(compute_prime_factors(number_to_factor));

    std::cout << "The primes of " << number_to_factor << " are: ";
    print_primes(prime_factors);
}

void print_primes(const std::vector<long>& primes)
{
    std::string prefix("[");
    for (int prime : primes) {
        std::cout << prefix << prime;
        prefix = ", ";
    }
    std::cout << "]" << std::endl;
}
