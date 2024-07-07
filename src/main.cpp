// 07/07/2024
// Main file

#include <iostream>
#include <fstream>
#include <gmpxx.h>

#include "../include/crypto.h"

using namespace std;

int main() {
    Crypto crypto;

    mpz_class privKey = crypto.genPriv();
    mpz_class pubKey  = crypto.genPub();

    ofstream priv("./private.key");
    ofstream pub("./public.key");

    priv << hex << privKey;
    pub << hex << pubKey;

    priv.close();
    pub.close();

    mpz_class message("123456789");
    mpz_class ciphertext = crypto.encrypt(message);

    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Plaintext: " << crypto.decrypt(ciphertext) << endl;

    return 0;
}
