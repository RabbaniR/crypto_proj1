#ifndef decrypt_h
#define decrypt_h

#include <iostream>
#include <tuple>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime> 

typedef std::tuple<char, int, int> revKey;

bool decryptLoop(std::string& plaintext, std::string& ciphertext, char* valArr);

//Decrypts the ciphertext and stores it into the plaintext
bool decryptString(std::string& plaintext, std::string& ciphertext, char* valArr);

//Counts the frequency of each key
void countKeyFreq(int* keyFreq, const std::string& ciphertext);

int findKeyPos(char c, int i);

bool testKey(std::vector<revKey>& vecRevKey, const std::string& candidate);

//Reverse generate keyspace
void reverseGenKeyspace(std::vector<revKey>& vecRevKey, const std::string& plaintext, std::string& ciphertext);
#endif  /* decrypt_h */
