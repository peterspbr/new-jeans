#pragma once

#include <gmpxx.h>

class Primes
{
private:
    // Nothing here lol.
public:
    Primes();
    bool isPrime(const mpz_class& n, int iterations);
    mpz_class generatePrime(int bitLength);
    ~Primes();
};
