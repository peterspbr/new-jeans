#include "../include/crypto.h"
#include "../include/primes.h"
#include "../include/mod_inverse.h"

Crypto::Crypto() {
    Primes primes;
    
    p = primes.generatePrime(byte_lenght);
    q = primes.generatePrime(byte_lenght);

    while ( q == p) q = primes.generatePrime(byte_lenght);
}

mpz_class Crypto::genPriv() {
    return n = p * q;
}

mpz_class Crypto::genPub() {
    ModInverse inverse;

    phi = (p - 1) * (q - 1);

    d = inverse.calculate(e, phi);

    return d;
}

mpz_class Crypto::encrypt(mpz_class pt) {
    mpz_class ct;
    mpz_powm(ct.get_mpz_t(), pt.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());

    return ct;
}

mpz_class Crypto::decrypt(mpz_class ct) {
    mpz_class pt;
    mpz_powm(pt.get_mpz_t(), ct.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());

    return pt;
}


Crypto::~Crypto() {}
