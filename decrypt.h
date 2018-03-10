#ifndef decrypt_h
#define decrypt_h

#include <iostream>
#include <tuple>
#include <string>
#include <sstream>
#include <algorithm>


typedef std::tuple<char, int, int> revKey;

//Decrypts the ciphertext and stores it into the plaintext
void decryptString(std::string& plaintext, std::string& ciphertext, char* valArr);

//Counts the frequency of each key
void countKeyFreq(int* keyFreq, const std::string& ciphertext);

int findKeyPos(char c, int i);

//Reverse generate keyspace
void reverseGenKeyspace(const std::string& plaintext, std::string& ciphertext);
#endif  /* decrypt_h */