using namespace std;

//*****Functions for zombieBattle*****\\

//placeZombieInRoom() {}

//displayField() {}

//countActiveZombies() {}

bool isValidInteger(int input) {
	return input>0;
}

int power(int base, int power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= base;
	}
	return result;
}