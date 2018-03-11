#include "decrypt.h"
#include "encrypt.h"
using namespace std;

//English dictionary (Test 2)
const vector<string> engWords = {"rereads","predestines","equippers","cavitation","bimolecular","lucubrations","cabin","bettas","quiverer","prussians","cosigner","dressier","bended","dethronement","inveigled","davenport","establish","ganges","rebroadcast","supered","bastiles","willable","abetted","motionlessness","demonic","flatter","bunyan","securely","tippiest","tongue","aw","cotyledonal","roomettes","underlies","miffs","inducement","overintellectually","fertilize","spasmodic","bacchanal","birdbrains","decoct","snakebite","galliard","boson","headmistress","unextended","provence","weakling","pirana","fiend","lairds","argils","comma"};

bool decryptLoop(string& plaintext, string& ciphertext, char* valArr){
    time_t startTime = time(nullptr);
    time_t endTime = time(nullptr);
    bool status = false;
    while(!status){
        status = decryptString(plaintext, ciphertext, valArr);
        keymap keyMap;
        char valMap[106];
        genKey(&keyMap, valMap);
        endTime = time(nullptr);
        uint elapsedTime = difftime(endTime, startTime);
        if(elapsedTime >= 180){ //3 minutes
            return false;
        }
    }
    return true;
}
bool decryptString(string& plaintext, string& ciphertext, char* valArr){
    //Read ciphertext
    istringstream cipherStream(ciphertext);
    string encryptedChar;
    char del = ',';
    string searchWord;
    while(getline(cipherStream, encryptedChar, del)){
        //cout << encryptedChar << ',';
        int charNum = stoi(encryptedChar);
        if(charNum >= 0 && charNum <= 105){ //Valid key
            plaintext += valArr[charNum];
            // cout << plaintext << endl;
            //Lookup key in value array
            if(valArr[charNum] == ' '){
                // cout << "Search: " << searchWord << endl;
                if(find(engWords.begin(), engWords.end(), searchWord) == engWords.end()){
                    return false;
                    // cout << "No words found" << endl;
                }
                searchWord = "";
            }
            else{
                searchWord += valArr[charNum];
            }
        }
        else{
            cerr << "Invalid key" << endl;
            exit(-1);
        }
    }
    return true;
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

bool testKey(vector<revKey>& vecRevKey){
    int size = vecRevKey.size();
    return (size > 106) ? false : true;
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

