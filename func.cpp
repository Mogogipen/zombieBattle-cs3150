#include <iostream>
#include "func.h"

using namespace std;

//*****Functions for zombieBattle*****\\

void placeZombieInRoom(char* zombie, char* rooms, int roomIndex) {
		zombie = &rooms[roomIndex];
		rooms[roomIndex] = 'Z';
}

void displayField(char* rooms, int roomSize, char** zombies, int zombieSize) {
	for (int i = 0; i < roomSize; i++) {
		for (int j = 1; j < 10; j++) {
			if (i/power(10, j) > 0) {
				cout << " ";
				continue;
			}
			break;
		}
		cout << rooms[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < roomSize; i++) {
		cout << i+1 << " ";
	}
	cout << endl;
}

int countActiveZombies(char** zombies, int zombieSize, char* stunnedLocation) {
	int result = 0;
	for (int i = 0; i < zombieSize; i++) {
		if (zombies[i] != stunnedLocation)
			result++;
	}
	return result;
}

bool isValidInteger(int input) {
	return input > 0;
}

int power(int base, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= base;
	}
	return result;
}