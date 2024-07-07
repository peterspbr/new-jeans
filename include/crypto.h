#pragma once

#include <gmpxx.h>

class Crypto {
private:
    unsigned int byte_lenght = 4096;
    mpz_class e = 65537;
    mpz_class p = 0;
    mpz_class q = 0;
    mpz_class n = 0;
    mpz_class phi = 0;
    mpz_class d = 0;
public:
    Crypto();
    mpz_class genPriv();
    mpz_class genPub();
    mpz_class encrypt(mpz_class pt);
    mpz_class decrypt(mpz_class ct);
    ~Crypto();
};
