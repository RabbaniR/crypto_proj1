#include "encrypt.h"
using namespace std;

void genKey(keymap* key) {
	//key skeleton
	vector<int> nums;
	for (int i = 0; i < 106; i++) {
		nums.push_back(i);
	}

	for (int i = 0; i < 106; i++) {
		char letterBeingMapped;
		//select random number between 0 and upper array limit
		srand(time(0)); //seed for pseudo-random number generation
		int r = rand() % nums.size();
		int randomlySelected = nums.at(r);		//select num in rth position in vector
		nums.erase(nums.begin() + r);	//remove current rth position so it's not reused

		//check if a has all kays assigned
		if (key->count('a') < 7) {
			letterBeingMapped = 'a';
		}
		//check if b has all kays assigned
		else if (key->count('b') < 1) {
			letterBeingMapped = 'b';
		}
		//check if c has all kays assigned
		else if (key->count('c') < 2) {
			letterBeingMapped = 'c';
		}
		else if (key->count('d') < 4) {
			letterBeingMapped = 'd';
		}
		else if (key->count('e') < 10) {
			letterBeingMapped = 'e';
		}
		else if (key->count('f') < 2) {
			letterBeingMapped = 'f';
		}
		else if (key->count('g') < 2) {
			letterBeingMapped = 'g';
		}
		else if (key->count('h') < 5) {
			letterBeingMapped = 'h';
		}
		else if (key->count('i') < 6) {
			letterBeingMapped = 'i';
		}
		else if (key->count('j') < 1) {
			letterBeingMapped = 'j';
		}
		else if (key->count('k') < 1) {
			letterBeingMapped = 'k';
		}
		else if (key->count('l') < 3) {
			letterBeingMapped = 'l';
		}
		else if (key->count('m') < 2) {
			letterBeingMapped = 'm';
		}
		else if (key->count('n') < 6) {
			letterBeingMapped = 'n';
		}
		else if (key->count('o') < 6) {
			letterBeingMapped = 'o';
		}
		else if (key->count('p') < 2) {
			letterBeingMapped = 'p';
		}
		else if (key->count('q') < 1) {
			letterBeingMapped = 'q';
		}
		else if (key->count('r') < 5) {
			letterBeingMapped = 'r';
		}
		else if (key->count('s') < 5) {
			letterBeingMapped = 's';
		}
		else if (key->count('t') < 7) {
			letterBeingMapped = 't';
		}
		else if (key->count('u') < 2) {
			letterBeingMapped = 'u';
		}
		else if (key->count('v') < 1) {
			letterBeingMapped = 'v';
		}
		else if (key->count('w') < 2) {
			letterBeingMapped = 'w';
		}
		else if (key->count('x') < 1) {
			letterBeingMapped = 'x';
		}
		else if (key->count('y') < 2) {
			letterBeingMapped = 'y';
		}
		else if (key->count(' ') < 19) {
			letterBeingMapped = ' ';
		}
		else {
			//must be z
			letterBeingMapped = 'z';
		}
		key->insert(pair<const char, int>((const char)letterBeingMapped, randomlySelected));
	}
}

void encryptString(const string& plaintext, keymap* key) {
	//encrypt using key & build encrypted input
	string ciphertext;
	for (int i = 0; i < plaintext.size(); i++) {
		//character iterator
		char c = plaintext[i];
		//encryption depends on the position of the character
		int keyPos = i % key->count(c);
			//cout << keyPos << " of " << keyCount << "  ";
		//use position to pick encryption
		keymapItr ret = key->find(c);
			//multimap<char, int>::iterator it = ret.first;
		int chosenEncryption;
		for (int i = 0; i <= keyPos; ++ret) {		// it != ret.second && 
			i++;
			chosenEncryption = ret->second;
			//cout << ' ' << chosenEncryption;
		}

		//cout << "chosen val: " << chosenEncryption << '\n';

		//build encrypted string
		ciphertext += to_string(chosenEncryption) + ",";

		//cout << c << i << "\n";
	}

    //Delete the last comma at the end of the ciphertext
    ciphertext.erase(ciphertext.size()-1);

    //Print plain and ciphertext
	cout << plaintext << "\n\n";
	cout << ciphertext << "\n\n";
	//ofstream myfile("encrypted.txt", ios_base::app);
	//myfile << plaintext << "\n";
	//myfile << ciphertext << "\n\n";
	//myfile.close();
}

void printKeyMap(keymap* key){
    for (keymapItr it = key->begin(); it != key->end(); ++it) {
		cout << "  [" << it->first << ", " << it->second << "]" << endl;
		//myfile  << "  [" << it->first << ", " << it->second << "], ";
	}
}