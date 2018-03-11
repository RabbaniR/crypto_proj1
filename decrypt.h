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

//Loop for decryptString with different keymap and lookup table
bool decryptLoop(std::string& plaintext, std::string& ciphertext, char* valArr);

//Decrypts the ciphertext and stores it into the plaintext
bool decryptString(std::string& plaintext, std::string& ciphertext, char* valArr);

//Find key position using j mod L (Test 1)
int findKeyPos(char c, int i);

//Test key to see if it works (Test 1)
bool testKey(std::vector<revKey>& vecRevKey);

//Reverse generate keyspace (Test 1)
void reverseGenKeyspace(std::vector<revKey>& vecRevKey, const std::string& plaintext, std::string& ciphertext);

#endif  /* decrypt_h */