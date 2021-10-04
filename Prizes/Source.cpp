// Hubert Bukowski | x00161897 - CREATOR

/*
REFERENCES:

Search function:
Week 3 Notes ( Introduction to Functions )
https://stackoverflow.com/questions/3909784/how-do-i-find-a-particular-value-in-an-array-and-return-its-index
*/

#include <iostream>
#include <random>
#include <ctime>
bool search(int array[], int lenArray, int toFind);

int main() {

	const int NUMFINALISTS = 25;

	int finalists[NUMFINALISTS];

	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(1, 25);

	// An Algorithm which populates the finalists array with the number of specified finalists
	for (int finalistNum = 0; finalistNum < NUMFINALISTS; finalistNum++) {
		int randNum = intDistro(defEngine);
		// If finalist index is greater than 0, compare random number to other numbers in the array
		if (finalistNum != 0) {
			// Loop and reassign the random number until it is unique
			while (search(finalists, finalistNum, randNum)) {
				for (int i = 0; i < finalistNum; i++) {
					if (randNum == finalists[i]) {
						randNum = intDistro(defEngine);
					}
				}
			}
		}
		finalists[finalistNum] = randNum;
		std::cout << finalists[finalistNum] << std::endl;
	}

	// Algorithm which loops through the number of prizes, for each prize it chooses a random winning number (1-25)
	for (int prizeNum = 1; prizeNum <= 4; prizeNum++) {
		int winner = intDistro(defEngine);
		for (int finalistNum = 0; finalistNum < NUMFINALISTS; finalistNum++) { // Loops and compares winning number to 25 finalists
			// If this finalist is a winner, print out a message and set their value to null, so as to avoid repeating winners
			if (finalists[finalistNum] == winner) {
				std::cout << "Winner of prize " << prizeNum << " is finalist number " << finalists[finalistNum] << std::endl;
				finalists[finalistNum] = NULL;
			}
		}
	}
	return 0;
}

// A search function which loops through a passed array and looks for a specified value until returns true/false
bool search(int array[], int lenArray, int toFind) {
	for (int i = 0; i < lenArray; i++) {
		if (array[i] == toFind) {
			return true;
		}
	}
	return false;
}