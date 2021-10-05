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

	const int NUMPRIZES = 4;
	const int NUMFINALISTS = 25;
	int finalists[NUMFINALISTS];
	int previousWinners[NUMPRIZES];

	std::default_random_engine defEngine(time(0));
	std::uniform_int_distribution<int> intDistro(1, 25);

	// An loop which populates the finalists array with the number of specified finalists
	for (int finalistNum = 0; finalistNum < NUMFINALISTS; finalistNum++) {
		int finalistNumber = finalistNum + 1;
		finalists[finalistNum] = finalistNumber;
	}

	// Algorithm which loops through the number of prizes, for each prize it chooses a random winning number (1-25)
	for (int prizeNum = 0; prizeNum < NUMPRIZES; prizeNum++) {
		int winner = intDistro(defEngine);
		// Loop while the new winning value is in the previous winners array and assign a new random
		while (search(previousWinners, NUMPRIZES, winner)) {
			winner = intDistro(defEngine);
		}
		for (int finalistNum = 0; finalistNum < NUMFINALISTS; finalistNum++) { // Loops and compares winning number to 25 finalists
			// If this finalist is a winner, print out a message and add the winning value to winner array so as to avoid repeating winners
			if (finalists[finalistNum] == winner) {
				std::cout << "Winner of prize " << prizeNum+1 << " is finalist number " << finalists[finalistNum] << std::endl;
				previousWinners[prizeNum] = winner;
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