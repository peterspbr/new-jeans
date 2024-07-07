// 07/07/2024
// Main file

#include <iostream>

#include "../include/crypto.h"

using namespace std;

int main() {
    Crypto crypto;

    cout << "Private key: " << crypto.genPriv() << endl;
    cout << "Public key: " << crypto.genPub() << endl;
    cout << endl;

    mpz_class message("123456789");
    mpz_class ciphertext = crypto.encrypt(message);

    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Plaintext: " << crypto.decrypt(ciphertext) << endl;

    return 0;
}
