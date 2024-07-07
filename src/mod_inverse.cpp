#include "../include/mod_inverse.h"

ModInverse::ModInverse(){}

mpz_class ModInverse::calculate(mpz_class a, mpz_class m) {
    mpz_class m0 = m, t, q;
    mpz_class x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

ModInverse::~ModInverse() {}
