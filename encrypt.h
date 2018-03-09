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
void genKey(keymap* key);

void encryptString(const std::string& toEncrypt, keymap* key);

bool encryptDriver(std::string candidates[], keymap* key);

//Prints the keymap
void printKeyMap(keymap* key);

#endif  /* encrypt_h */