#ifndef encrypt_h
#define encrypt_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime> 

//Renaming multimap<const char, int> to keymap for readability
typedef std::multimap<const char, int> keymap;
typedef std::multimap<const char, int>::iterator keymapItr;

//Generates a keymap 
void genKey(keymap* key, char* valArr);

void encryptString(std::string& ciphertext, const std::string& plaintext, keymap* key);

//Prints the keymap
void printKeyMap(keymap* key);
void printValMap(char* valMap);

#endif  /* encrypt_h */