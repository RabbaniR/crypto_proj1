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
