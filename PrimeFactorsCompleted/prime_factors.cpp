#include "prime_factors.h"

std::vector<long> compute_prime_factors(long n)
{
    std::vector<long> result {};

    for (long factor = 2; factor <= n; ++factor) {
        while (n % factor == 0) {
            result.push_back(factor);
            n /= factor;
        }
    }

    return result;
}
