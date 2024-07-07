#pragma once

#include <gmpxx.h>

class ModInverse {
private:
    mpz_class t, q = 0;
public:
    ModInverse();
    mpz_class calculate(mpz_class a, mpz_class m);
    ~ModInverse();
};
