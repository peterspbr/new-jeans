#include "../include/primes.h"

Primes::Primes()
{
}

bool Primes::isPrime(const mpz_class& n, int iterations = 50) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    mpz_class d = n - 1;
    int r = 0;

    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    gmp_randclass rand(gmp_randinit_mt);
    rand.seed(time(NULL));

    for (int i = 0; i < iterations; i++) {
        mpz_class a = rand.get_z_range(n - 3) + 2;
        mpz_class x;
        mpz_powm(x.get_mpz_t(), a.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());

        if (x == 1 || x == n - 1) continue;

        bool composite = true;
    
	for (int j = 0; j < r - 1; j++) {
            mpz_powm_ui(x.get_mpz_t(), x.get_mpz_t(), 2, n.get_mpz_t());
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        
	if (composite) return false;
    }

    return true;
}

mpz_class Primes::generatePrime(int bitLength) {
    gmp_randclass rand(gmp_randinit_mt);
    rand.seed(time(NULL));

    mpz_class prime;

    do {
        prime = rand.get_z_bits(bitLength);
        prime |= 1; // Ensure the number is odd
    } while (!isPrime(prime));

    return prime;
}

Primes::~Primes()
{
}
