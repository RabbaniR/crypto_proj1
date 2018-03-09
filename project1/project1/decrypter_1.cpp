//Get input: (ciphertext)
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


string testKey(vector<tuple<char, int, int>> key) {
	string deciphered = "This is the correct plaintext!";

	//check that key is legal
	int keyspace = key.size();
	if (keyspace > 106) {
		return "This candidate is not the correct plaintext";
	}

	return deciphered;
}

std::vector<tuple<char, int, int>> reverseGenKeyspace(string s, string ciphertxt) {
	vector<tuple<char, int, int>> keyspace;
		std::string delimiter = ",";
		size_t pos = 0;
		std::string token;
	//	while ((pos = ciphertxt.find(delimiter)) != std::string::npos) {
	//		char currentChar = get<0>(keyspace[i]);
	//		token = ciphertxt.substr(0, pos);
	//	}
	for (int i = 0; i < s.size(); i++) {
		//
		if (((pos = ciphertxt.find(delimiter)) == std::string::npos)) {
			//no more enciphered values
			break;
		}
		token = ciphertxt.substr(0, pos);

		//character iterator for plaintext
		const char c = s[i];
		int posn;
		//encryotion depends on the position of the character
		if (c == 'a' || c == 't') {
			posn = i % 7;
		}
		else if (c == 'b' || c == 'j' || c == 'k' || c == 'q' || c ==  'v' || c == 'x' || c == 'z') {
			posn = i % 1;
		}
		else if (c == 'c' || c == 'f' || c == 'g' || c == 'm' || c == 'p' || c == 'u' || c == 'w' || c == 'y') {
			posn = i % 2;
		}
		else if (c == 'd') {
			posn = i % 4;
		}
		else if (c == 'e') {
			posn = i % 10;
		}
		else if (c == 'h' || c == 'r' || c == 's') {
			posn = i % 5;
		}
		else if (c == 'i' || c == 'n' || c == 'o') {
			posn = i % 6;
		}
		else if (c == 'l') {
			posn = i % 3;
		}
		else {
			//the character is a space character
			posn = i % 19;
		}
		tuple<char, int, int> newTuple = std::make_tuple(c, posn, stoi(token));
		keyspace.push_back(newTuple);


		ciphertxt.erase(0, pos + delimiter.length());
	}

	sort(keyspace.begin(), keyspace.end());
	keyspace.erase(unique(keyspace.begin(), keyspace.end()), keyspace.end());


	sort(keyspace.begin(), keyspace.end());
	keyspace.erase(unique(keyspace.begin(), keyspace.end()), keyspace.end());

	return keyspace;
}

int main() {
	string ciphertext, plaintext;

	//Get input: (ciphertext)
	cout << "Enter the ciphertext: ";
	cin >> ciphertext;

	//for each plaintext, try to backwards build the key using the scheduling algorithm
	std::string candidate1 = "dipped ligatured cannier cohabitation cuddling coiffeuses pursuance roper eternizes nullo framable paddlings femur bebop demonstrational tuberculoid theocracy women reappraise oblongatae aphasias loftiness consumptive lip neurasthenically dutchmen grift discredited resourcefulness malfeasants swallowed jogger sayable lewder editorials demimondaine tzaritza arrogations wish indisputable reproduces hygrometries gamuts alight borderlines draggle reconsolidated anemometer rowels staggerers grands nu";
	std::string candidate2 = "rereads predestines equippers cavitation bimolecular lucubrations cabin bettas quiverer prussians cosigner dressier bended dethronement inveigled davenport establish ganges rebroadcast supered bastiles willable abetted motionlessness demonic flatter bunyan securely tippiest tongue aw cotyledonal roomettes underlies miffs inducement overintellectually fertilize spasmodic bacchanal birdbrains decoct snakebite galliard boson headmistress unextended provence weakling pirana fiend lairds argils comma";
	std::string candidate3 = "trawling responsiveness tastiest pulsed restamps telescoping pneuma lampoonist divas theosophists pustules checkrowed compactor conditionals envy hairball footslogs wasteful conjures deadfall stagnantly procure barked balmier bowery vagary beaten capitalized undersized towpath envisages thermoplastic rationalizers professions workbench underarm trudger icicled incisive oilbirds citrins chambrays ungainliness weazands prehardened dims determinants fishskin cleanable henceforward misarranges fine ";
	std::string candidate4 = "dean iller playbooks resource anesthetic credibilities nonplus tzetzes incursions stooged envelopments girdling risibility thrum repeaters catheterizing misbestowed cursing malingerers ensconces lippiest accost superannuate slush opinionated rememberer councils mishandling drivels juryless slashers tangent roistering scathing apprenticing fleabite sault achier quantize registrable nobbler sheaf natantly kashmirs dittoes scanned emissivity iodize dually refunded portliest setbacks eureka needines";
	std::string candidate5 = "mammate punners octette asylum nonclinically trotters slant collocation cardiology enchants ledge deregulated bottommost capsulate biotechnologies subtended cloddiest training joneses catafalque fieldmice hostels affect shrimper differentiations metacarpus amebas sweeter shiatsu oncoming tubeless menu professing apostatizing moreover eumorphic casked euphemistically programmability campaniles chickpea inactivates crossing defoggers reassures tableland doze reassembled striate precocious noncomba";

	std::vector<tuple<char, int, int>> keyS1 = reverseGenKeyspace(candidate1, ciphertext);
	std::vector<tuple<char, int, int>> keyS2 = reverseGenKeyspace(candidate2, ciphertext);
	std::vector<tuple<char, int, int>> keyS3 = reverseGenKeyspace(candidate3, ciphertext);
	std::vector<tuple<char, int, int>> keyS4 = reverseGenKeyspace(candidate4, ciphertext);
	std::vector<tuple<char, int, int>> keyS5 = reverseGenKeyspace(candidate5, ciphertext);

	//apply ciphertext to all keyspaces generated to generate 5 keys
			//std::multimap<char, int> key1 = reverseGenKey(keyS1, ciphertext);
	string generatedPlaintext1 = testKey(keyS1);
	string generatedPlaintext2 = testKey(keyS2);
	string generatedPlaintext3 = testKey(keyS3);
	string generatedPlaintext4 = testKey(keyS4);
	string generatedPlaintext5 = testKey(keyS5);

	cout << candidate1 << "\ncandidate1: " << generatedPlaintext1 << "\n\n";
	cout << candidate2 << "\ncandidate2: " << generatedPlaintext2 << "\n\n";
	cout << candidate3 << "\ncandidate3: " << generatedPlaintext3 << "\n\n";
	cout << candidate4 << "\ncandidate4: " << generatedPlaintext4 << "\n\n";
	cout << candidate5 << "\ncandidate5: " << generatedPlaintext5 << "\n\n";

}