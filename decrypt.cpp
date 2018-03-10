#include "decrypt.h"
using namespace std;

void decryptString(string& plaintext, string& ciphertext, char* valArr){
    //Read ciphertext
    istringstream cipherStream(ciphertext);
    string encryptedChar;
    char del = ',';
    while(getline(cipherStream, encryptedChar, del)){
        //cout << encryptedChar << ',';
        int charNum = stoi(encryptedChar);
        if(charNum >= 0 && charNum <= 105){ //Valid key
            //Lookup key in value array
            plaintext += valArr[charNum];
        }
        else{
            cerr << "Invalid key" << endl;
            exit(-1);
        }
    }
}

void countKeyFreq(int* keyFreq, const string& ciphertext){
   //Read ciphertext
    istringstream cipherStream(ciphertext);
    string encryptedChar;
    char del = ',';
    while(getline(cipherStream, encryptedChar, del)){
        //cout << encryptedChar << ',';
        int charNum = stoi(encryptedChar);
        if(charNum >= 0 && charNum <= 105){ //Valid key
            //Lookup key in value array
            keyFreq[charNum] += 1;
        }
        else{
            cerr << "Invalid key" << endl;
            exit(-1);
        }
    }

    //DEBUG: Print out int array
    for(int i = 0; i < 106; i++){
        cout << i << ',' << keyFreq[i] << endl;
    }
    cout << endl;
}

int findKeyPos(char c, int i){
    //char c: character of the plaintext at index i
    //int i: index of the plaintext
    int keyIndex;
    if (c == 'a' || c == 't') {
        keyIndex = i % 7;
    }
    else if (c == 'b' || c == 'j' || c == 'k' || c == 'q' || c ==  'v' || c == 'x' || c == 'z') {
        keyIndex = i % 1;
    }
    else if (c == 'c' || c == 'f' || c == 'g' || c == 'm' || c == 'p' || c == 'u' || c == 'w' || c == 'y') {
        keyIndex = i % 2;
    }
    else if (c == 'd') {
        keyIndex = i % 4;
    }
    else if (c == 'e') {
        keyIndex = i % 10;
    }
    else if (c == 'h' || c == 'r' || c == 's') {
        keyIndex = i % 5;
    }
    else if (c == 'i' || c == 'n' || c == 'o') {
        keyIndex = i % 6;
    }
    else if (c == 'l') {
        keyIndex = i % 3;
    }
    else {
        //the character is a space character
        keyIndex = i % 19;
    }
    return keyIndex;
}

bool testKey(vector<revKey>& vecRevKey, const string& candidate){
    int size = vecRevKey.size();
    if(size > 106){
        return false;
    }
    else{
        cout << "Plaintext:\n" << candidate << endl;
        return true;
    }
}

void reverseGenKeyspace(vector<revKey>& vecRevKey, const string& plaintext, string& ciphertext){
    //Read ciphertext
    istringstream cipherStream(ciphertext);
    string token;
    char del = ',';
    int index = 0;
    while(getline(cipherStream, token, del)){
        //cout << token << ',';
        int charNum = stoi(token);
        if(charNum >= 0 && charNum <= 105){ //Valid key
            int keyIndex = findKeyPos(plaintext[index], index);
            //cout << plaintext[index] << ' ' << keyIndex << ' ' << charNum << endl;
            vecRevKey.push_back(make_tuple(plaintext[index], keyIndex, charNum));
        }
        else{
            cerr << "Invalid key" << endl;
            exit(-1);
        }
        //Increment index
        index++;
    }
    sort(vecRevKey.begin(), vecRevKey.end());
    vecRevKey.erase(unique(vecRevKey.begin(), vecRevKey.end()), vecRevKey.end());
}

