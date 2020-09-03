//Author: Valerio Puente
//
//Serial Number: 62
//
//Due Date: 10/29/2018
//Programming Assignment Number 5
//Fall 2018 - CS 1428 - 003
//
//Instructor: Husain Gholoom
//
//This program will encrypt a text file using a simple substitution cypher
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//Key where each value corresponds to the cyphered version of its index
	const int SIZE = 127;
	const int NUMBERS_BEGINNING = 48;
	const int NUMBERS_END = 57;
	const int LETTERS_BEGINNING = 65;
	const int LETTERS_END = 90;
	int cypherKey[SIZE];
	int tempIndex = 0;

	//Collection of all cypher keys
	const char CYPHER_TEXT_KEY[] = { 'E', 'M', 'N', 'V', 'D', 'L', 'W', 'A', 'U', 'C',
								'P', 'O', 'K', 'X', 'Q', 'B', 'I', 'Z', 'J', 'R',
								'Y', 'T', 'G', 'S', 'H', 'F' };
	const char CYPHER_NUMBER_KEY[] = { '9', '8', '7', '6', '5', '4', '3', '2', '1', '0' };
	const char CYPHER_SYMBOLS_KEY[] = { '{', '}', ']', '[', '@', '?', '>', ';', '/', '.',
										'+', '*', ')', '(', '\'', '&', '%', '$', '!' };
	const char CYPHER_SPACE_KEY[] = { '^', '~', '#', '`', ':' };

	const int CHARACTERS_IN_FILE = 600;
	char TEXT_FILE[CHARACTERS_IN_FILE];
	char newTextFile[CHARACTERS_IN_FILE];

	ifstream originalFile("eFile.txt", ios::binary);
	char c;
	int i = 0;
	while (originalFile.get(c)) {
		TEXT_FILE[i] = c;
		i++;
	}
	originalFile.close();

	for (int i = 0; i < CHARACTERS_IN_FILE; i++) {
		int index;

		index = int(toupper(TEXT_FILE[i]));
		if (index >= LETTERS_BEGINNING && index <= LETTERS_END) {
			cout << CYPHER_TEXT_KEY[index - LETTERS_BEGINNING];
		}
		if (index >= NUMBERS_BEGINNING && index <= NUMBERS_END) {
			cout << CYPHER_NUMBER_KEY[index - NUMBERS_BEGINNING];
		}
		if (index == 32) {
			cout << CYPHER_SPACE_KEY[tempIndex];
			tempIndex++;
			if (tempIndex == 5) {
				tempIndex = 0;
			}
		}
		if (index == 39) {
			//Comma
			cout << CYPHER_SYMBOLS_KEY[4];
		}
		if (index == 44) {
			//Comma
			cout << CYPHER_SYMBOLS_KEY[7];
		}
		if (index == 45) {
			//Dash
			cout << CYPHER_SYMBOLS_KEY[8];
		}
		if (index == 46) {
			//Period
			cout << CYPHER_SYMBOLS_KEY[9];
		}
	}


	cout << "\n\nThis algorithm is designed and Implemented by\n"
		<< "Valerio Puente - Encryption Data Group\n"
		<< "October 29 - 2018";
	cin.get();


	return 0;
}

