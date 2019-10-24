#include <iostream>
#include <cstdlib> //For rand()
#include "func.h"

using namespace std;

//*****Functions for zombieBattle*****\\

char* placeZombieInRoom(char* zombie, char* rooms, int roomIndex) {
		zombie = &rooms[roomIndex];
		rooms[roomIndex] = 'Z';
		return zombie;
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

void randomizeZombies(char** zombies, char* rooms, int zombieSize, int roomSize, int regeneration, char* stunnedLocation) {
	for (int i = 0; i < roomSize; i++) {
		rooms[i] = 'E';
	}
	for (int i = 0; i < zombieSize; i++) {
		if (zombies[i] != stunnedLocation) {
			int roomIndex = rand() % roomSize;
			zombies[i] = placeZombieInRoom(zombies[i], rooms, roomIndex);
		} else {
			if (rand() % 100 < regeneration) {
				int roomIndex = rand() %roomSize;
				zombies[i] = placeZombieInRoom(zombies[i], rooms, roomIndex);
			}
		}
	}
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