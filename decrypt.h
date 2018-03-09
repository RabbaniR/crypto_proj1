#ifndef decrypt_h
#define decrypt_h

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

//Decrypts the ciphertext and stores it into the plaintext
void decryptString(std::string& plaintext, std::string& ciphertext, char* valArr);

#endif  /* decrypt_h */