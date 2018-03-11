#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include "encrypt.h"
#include "decrypt.h"
using namespace std;

//For Test 1
const string candidate1 = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";
const string candidate2 = "rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma";
const string candidate3 = "trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ";
const string candidate4 = "dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines";
const string candidate5 = "mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba";

int main(int argc, char* argv[]){
    string ciphertext, plaintext;

    //Keymap and value map
    keymap keyMap;      //Each key (char) assigned num [0~105]
    char valueMap[106]; //Each index [0~105] assigned the char

    //Generate keymap
    genKey(&keyMap, valueMap);
    
    //For debugging:
    //Print key list and value map
    //printKeyMap(&keyMap);
    //printValMap(valueMap);

    //argv[1] = Chooses which test (either 1 or 2)
    if(argc == 2){
        //Get input: (ciphertext)
        cout << "Enter the ciphertext: ";
        cin >> ciphertext;

        //Input arguement has to be a number
        int test = stoi(argv[1]);
        //Perform test 1
        if(test == 1){
            /**
            //Testing Code:
            int choice;
            cout << "Choose plaintext candidate (1~5): ";
            cin >> choice;

            switch(choice){
                case 1:
                    encryptString(ciphertext, candidate1, &keyMap);
                    cout << "Plaintext: " << endl << candidate1 << endl;
                    break;
                case 2:
                    encryptString(ciphertext, candidate2, &keyMap);
                    cout << "Plaintext: " << endl << candidate2 << endl;

                    break;
                case 3:
                    encryptString(ciphertext, candidate3, &keyMap);
                    cout << "Plaintext: " << endl << candidate3 << endl;

                    break;
                case 4:
                    encryptString(ciphertext, candidate4, &keyMap);
                    cout << "Plaintext: " << endl << candidate4 << endl;

                    break;
                case 5:
                    encryptString(ciphertext, candidate5, &keyMap);
                    cout << "Plaintext: " << endl << candidate5 << endl;

                    break;
                default:
                    //Do nothing
                    cout << "Choose a number between 1~5" <<endl;
                    break;
            }
            */

            vector<revKey> keyS1, keyS2, keyS3, keyS4, keyS5;

            reverseGenKeyspace(keyS1, candidate1, ciphertext);
            reverseGenKeyspace(keyS2, candidate2, ciphertext);
            reverseGenKeyspace(keyS3, candidate3, ciphertext);
            reverseGenKeyspace(keyS4, candidate4, ciphertext);
            reverseGenKeyspace(keyS5, candidate5, ciphertext);

            if(testKey(keyS1)){
                cout << "Plaintext: " << candidate1 << endl;
            }
            else if(testKey(keyS2)){
                cout << "Plaintext: " << candidate2 << endl;
            }
            else if(testKey(keyS3)){
                cout << "Plaintext: " << candidate3 << endl;
            }
            else if(testKey(keyS4)){
                cout << "Plaintext: " << candidate4 << endl;
            }
            else if(testKey(keyS5)){
                cout << "Plaintext: " << candidate5 << endl;
            }
            else{
                cout << "Could not decrypt" << endl;
            }
        }
        else if(test == 2){ //Perform test 2
            /**
             * string test2 = "rereads predestines equippers cavitation";
             * encryptString(ciphertext, test2, &keyMap);
             */

            //Decrypt
            bool result = decryptLoop(plaintext, ciphertext, valueMap);
            if(result){
                //Print output: (plaintext)
                cout << "Plaintext: " << plaintext << endl;
            }
            else{
                cout << "Could not decrypt" << endl;
            }
        }
        else{
            cout << "Enter 1 to perform test 1 and 2 to perform test 2." << endl;
        }
    }
    else{
        cout << "Enter only 1 or 2 as the arguement." << endl;
        cout << "Ex) ./Kim-Rabbani-Walker-decrypt 1" << endl;
    }
}
