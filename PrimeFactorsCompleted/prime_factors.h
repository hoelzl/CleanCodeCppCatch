#pragma once

#include <vector>
#include <string>

std::vector<long> compute_prime_factors(long n);

std::string format_primes(const std::vector<long>& primes);

void compute_and_write_primes(long n, std::ostream& os);