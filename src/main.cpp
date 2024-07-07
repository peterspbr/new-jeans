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
    // Do the RSA magic
    Crypto crypto;

    // Gen key pair
    mpz_class privKey = crypto.genPriv();
    mpz_class pubKey  = crypto.genPub();

    // Output key pairs to files
    ofstream priv("./private.key");
    ofstream pub("./public.key");

    priv << hex << privKey;
    pub << hex << pubKey;

    priv.close();
    pub.close();

    // Get file contents to encrypt
    string message;

    ifstream file("data.txt");
    string line;
    
    while (getline(file, line)) {
        message += line;
    }
    
    file.close();

    // Convert the message from string to int (RSA will work only with int)
    mpz_class messageInt = stringToMpz(message);

    mpz_class ciphertext = crypto.encrypt(messageInt); // Finally, encrypt the data

    // Write encrypted data to file
    string encrypted_file_path = "data.nj";
    ofstream encrypted_file(encrypted_file_path);
    encrypted_file << mpzToString(ciphertext);
    encrypted_file.close();

    cout << "Ciphertext written to " << encrypted_file_path << endl;

    // Get the encrypted message and decrypt
    // ** DECRYPTING FOR TESTING PURPOSES **
    string enc_message;
    ifstream enc_file("data.nj");
    string enc_line;
    
    while (getline(enc_file, enc_line)) {
        enc_message += enc_line;
    }
    
    file.close();

    mpz_class plaintext = stringToMpz(enc_message);

    cout << "Plaintext: ";
    cout << mpzToString(crypto.decrypt(ciphertext)) << endl;

    return 0;
}
