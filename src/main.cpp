// 07/07/2024
// Main file

#include <iostream>
#include <fstream>
#include <gmpxx.h>
#include <string>

#include "../include/crypto.h"

using namespace std;

mpz_class stringToMpz(const std::string& input) {
    mpz_class result;
    mpz_import(result.get_mpz_t(), input.size(), 1, sizeof(input[0]), 0, 0, input.data());
 
    return result;
}

std::string mpzToString(const mpz_class& input) {
    size_t count = (mpz_sizeinbase(input.get_mpz_t(), 2) + 7) / 8; // Number of bytes
    std::string output(count, 0);
    mpz_export(&output[0], &count, 1, sizeof(output[0]), 0, 0, input.get_mpz_t());
    
    return output;
}

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

    string message = "Hello, world";
    mpz_class messageInt = stringToMpz(message);

    mpz_class ciphertext = crypto.encrypt(messageInt);

    cout << "Ciphertext: ";
    cout << mpzToString(ciphertext) << endl;

    cout << "Plaintext: ";
    cout << mpzToString(crypto.decrypt(ciphertext)) << endl;

    return 0;
}
