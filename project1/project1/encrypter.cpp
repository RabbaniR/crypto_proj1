// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime> 
using namespace std;

multimap<const char, int> genKey() {
	multimap<const char, int> key;
	//key skeleton
	std::vector<int> nums;
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
		if (key.count('a') < 7) {
			letterBeingMapped = 'a';
		}
		//check if b has all kays assigned
		else if (key.count('b') < 1) {
			letterBeingMapped = 'b';
		}
		//check if c has all kays assigned
		else if (key.count('c') < 2) {
			letterBeingMapped = 'c';
		}
		else if (key.count('d') < 4) {
			letterBeingMapped = 'd';
		}
		else if (key.count('e') < 10) {
			letterBeingMapped = 'e';
		}
		else if (key.count('f') < 2) {
			letterBeingMapped = 'f';
		}
		else if (key.count('g') < 2) {
			letterBeingMapped = 'g';
		}
		else if (key.count('h') < 5) {
			letterBeingMapped = 'h';
		}
		else if (key.count('i') < 6) {
			letterBeingMapped = 'i';
		}
		else if (key.count('j') < 1) {
			letterBeingMapped = 'j';
		}
		else if (key.count('k') < 1) {
			letterBeingMapped = 'k';
		}
		else if (key.count('l') < 3) {
			letterBeingMapped = 'l';
		}
		else if (key.count('m') < 2) {
			letterBeingMapped = 'm';
		}
		else if (key.count('n') < 6) {
			letterBeingMapped = 'n';
		}
		else if (key.count('o') < 6) {
			letterBeingMapped = 'o';
		}
		else if (key.count('p') < 2) {
			letterBeingMapped = 'p';
		}
		else if (key.count('q') < 1) {
			letterBeingMapped = 'q';
		}
		else if (key.count('r') < 5) {
			letterBeingMapped = 'r';
		}
		else if (key.count('s') < 5) {
			letterBeingMapped = 's';
		}
		else if (key.count('t') < 7) {
			letterBeingMapped = 't';
		}
		else if (key.count('u') < 2) {
			letterBeingMapped = 'u';
		}
		else if (key.count('v') < 1) {
			letterBeingMapped = 'v';
		}
		else if (key.count('w') < 2) {
			letterBeingMapped = 'w';
		}
		else if (key.count('x') < 1) {
			letterBeingMapped = 'x';
		}
		else if (key.count('y') < 2) {
			letterBeingMapped = 'y';
		}
		else if (key.count(' ') < 19) {
			letterBeingMapped = ' ';
		}
		else {
			//must be z
			letterBeingMapped = 'z';
		}
		key.insert(pair<const char, int>((const char)letterBeingMapped, randomlySelected));


	}

	return key;
}
void encrypt(string toEncrypt, multimap<const char, int> key) {

	//encrypt using key & build encrypted input
	string excryptedInput = "";
	for (int i = 0; i < toEncrypt.size(); i++) {
		//character iterator
		char c = toEncrypt[i];
		//encryotion depends on the position of the character
		int posn = i % key.count(c);
			//std::cout << posn << " of " << keyCount << "  ";
		//use position to pick encryption
		std::multimap<char, int>::iterator ret;
		ret = key.find(c);
			//std::multimap<char, int>::iterator it = ret.first;
		int chosenEncryption;
		for (int i = 0; i <= posn; ++ret) {		// it != ret.second && 
			i++;
			chosenEncryption = ret->second;
			//std::cout << ' ' << chosenEncryption;
		}

		//std::cout << "chosen val: " << chosenEncryption << '\n';

		//build encrypted string
		excryptedInput += std::to_string(chosenEncryption) + ",";

		//std::cout << c << i << "\n";
	}
	std::cout << toEncrypt << "\n\n";
	std::cout << excryptedInput << "\n\n";
	ofstream myfile("encrypted.txt", std::ios_base::app);
	myfile << toEncrypt << "\n";
	myfile << excryptedInput << "\n\n";
	myfile.close();
}


bool encryptDriver(string candidates[]) {
	//generate key
	std::multimap<const char, int> key = genKey();
	ofstream myfile("encrypted.txt", std::ios_base::app);

	//std::cout << "Is map empty?" << key.empty();
	//DEBUG purposes, outputs the full key
	for (multimap<const char, int>::iterator it = key.begin(); it != key.end(); ++it) {
		cout << "  [" << (*it).first << ", " << (*it).second << "]" << endl;
		myfile  << "  [" << (*it).first << ", " << (*it).second << "], ";

	}
	myfile << "\n";
	myfile.close();

	string currentCandidate;
	//std::cout << sizeof(candidates);
	for (int i = 0; i <= 0; i++) {
		for (int i = 0; i < sizeof(candidates); i++) {
			currentCandidate = candidates[i];
			encrypt(currentCandidate, key);
		}
	}

	return 0;
}

int mainp()
{



	std::string candidate1 = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";
	std::string candidate2 = "rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma";
	std::string candidate3 = "trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ";
	std::string candidate4 = "dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines";
	std::string candidate5 = "mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba";

	string candidates[] = { candidate1, candidate2, candidate3, candidate4, candidate5 };

	bool status = encryptDriver(candidates);

	/*std::ifstream t("c:\\Users\\Rae\\Documents\\GitHub\\crypto_proj1\\project1\\test1_candidate_5_plaintexts.txt");
	std::string str;
	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
	std::istreambuf_iterator<char>());
	*/



	return 0;

}


