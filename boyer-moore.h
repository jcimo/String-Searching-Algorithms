// BOYER-MOORE STRING SEARCH ALGORITHM 

// ******ONLY WITH BAD CHAR, NO GOOD SUFFIX******* 

// param - inputfile, the input file
//
// returns a vector<int> indicating all indexes of the base that
// are equal to instances of the first char of the key found in
// the base string
//
// return an empty vector if the key string is not found
#include <fstream>

#define NUM_CHARS 256
#define NOT_FOUND -1 

//quick utility for max of two ints
int max(int a, int b){
	return ((a > b) ? a : b);
}

void fillBadChar(string key, int keyLength, int badCharTable[NUM_CHARS]){
	//initialize occurences to NOT_FOUND
	for(int i = 0; i < NUM_CHARS; i++){
		badCharTable[i] = NOT_FOUND; 
	}
	//fill in the table with the last occurence of a character in the key 
	for(int i = 0; i < keyLength; i++){
		badCharTable[ (int)key[i] ] = i; 
	}

	// cout << "badCharTable: ";
	// for(int i = 0; i < keyLength; i++){
	// 	cout << badCharTable[i] << " ";
	// }
	// cout << endl;
}

vector<int> boyer_moore_search(string base, string key) {
    vector<int> finds; //indexes where key is found 
	int baseLength = base.length();
	int keyLength = key.length(); 
	int badCharTable[NUM_CHARS]; 
	// cout << "Key: " << key << endl; 
	// cout << "Base: " << base << endl;
	int shiftIndex = 0; //location of the match

	//fill the badCharTable 
	fillBadChar(key, keyLength, badCharTable);

	while(shiftIndex <= (baseLength - keyLength)){
		// cout << "shiftIndex: " << shiftIndex << endl;
		int keyIndex = keyLength - 1; //start at the end 
		//keep searching backwards, checking that the characters line up 
		while(keyIndex >= 0 && key[keyIndex] == base[keyIndex + shiftIndex]){
			keyIndex--; 
		}
			
		//if the pattern is found, then keyIndex should be -1. add it to the vector
		if(keyIndex < 0){
			// cout << "Got it! " << " shiftIndex: " << shiftIndex << " keyIndex: " << keyIndex << endl;
				finds.push_back(shiftIndex);

			//shift to line up the next char in base lines up with the last occurence in the key
			//must check to see if we found the pattern at the end of the text 
			shiftIndex += (shiftIndex + keyLength < baseLength) ? keyLength - badCharTable[base[shiftIndex+keyLength]] : 1;  				
		}else {
			//shift so the bad character (not matched) aligns with the last occurence in the key
			//max is used to ensure we shift in the right direction
			
			shiftIndex += max(1, keyIndex - badCharTable[base[shiftIndex + keyIndex]]); 
		}	
	}

    return finds;
}