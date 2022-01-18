#include "prime_factors.h"

#include <string>
#include <sstream>

using namespace std::string_literals;

std::vector<long> prime_factors::compute_prime_factors(long n)
{
    std::vector<long> result{};

    for (long factor = 2; factor <= n; ++factor) {
        while (n % factor == 0) {
            result.push_back(factor);
            n /= factor;
        }
    }

    return result;
}

std::string prime_factors::format_primes(const std::vector<long>& primes)
{
    
    std::string result{};
    std::string prefix{};

    for (const long prime : primes) {
        result += prefix + std::to_string(prime);
        prefix = ", ";
    }
    return result;
}

void prime_factors::compute_and_write_primes(long n, std::ostream& os)
{
    const std::vector<long> prime_factors{compute_prime_factors(n)};
    os << "The primes of " << n << " are " << format_primes(prime_factors);
}
