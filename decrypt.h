#ifndef decrypt_h
#define decrypt_h

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

//Decrypts the ciphertext and stores it into the plaintext
void decryptString(std::string& plaintext, std::string& ciphertext, char* valArr);

//Counts the frequency of each key
void countKeyFreq(int* keyFreq, const std::string& ciphertext);

#endif  /* decrypt_h */