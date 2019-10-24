#include <iostream>	//For output to command line
#include <string>	//For string functions
#include <cstdlib>	//For rand function
#include <ctime>	//For time, used for srand() (seed generation)
#include "func.h"

using namespace std;

//*****This is a zombie killing game! (main cpp file)*****\\

char c = ' ';
char* const stunnedZombiesLocation = &c;

int main() {

	//Welcome the player

	cout << "Welcome to Zombie Splatter!!" << endl;
	cout << "You're trapped in a building with zombies!\nIf you run out of bullets you're going to die!\n" << endl;

	//Ask the player for game parameters (roomCount, zombieCount, & regeneration rate)

	int roomCount;
	int zombieCount;
	int regeneration;

	gatherInput:
	cout << "How many rooms are there in the building? ";
	cin >> roomCount;
	cout << "How many zombies are in the building? (If there's already more zombies than rooms, you're dead.) ";
	cin >> zombieCount;
	cout << "What are the chances that the zombie will regenerate (as a percentage)? ";
	cin >> regeneration;

	//Verify input, jump if invalid

	if (!isValidInteger(roomCount) || !isValidInteger(zombieCount) || regeneration > 100 || regeneration <= 0) {
		cout << "That is not valid input\n" << endl;
		cin.clear();
		cin.ignore(10, '\n');
		goto gatherInput;
	}
	if (zombieCount > roomCount) {
		cout << "Sorry, you inevitably die.\nGame Over" << endl;
		return 0;
	}

	//Initialize the game *********************************************
	
	srand(time(NULL)); //Seed rng

	char* rooms = new char[roomCount];	//Dynamic character array
	char* zombies[zombieCount];			//Array of zombie pointers

	//Set the loop parameters
	bool play = true;
	bool win = false;
	int bullets = 25;
	int activeZombies;

	//*****************************************************************

	while (play) {

		//Randomize the zombies and randomly regenerate them
		randomizeZombies(zombies, rooms, zombieCount, roomCount, regeneration, stunnedZombiesLocation);

		//Tell the player how many bullets they have left
		cout << "You have " << bullets << " bullets left!" << endl;

		//Display rooms in this format:
		//* * * * * * * * * *  *
		//1 2 3 4 5 6 7 8 9 10 11

		//Print the asterisks
		for (int i = 0; i < roomCount; i++) {
			//Place astrisks in-line with room numbers;
			for (int j = 1; j < 10; j++) {
				if (i/power(10, j) > 0) {
					cout << " ";
					continue;
				}
				break;
			}

			cout << "* ";
		}
		cout << endl;

		//Print the room numbers
		for (int i = 0; i < roomCount; i++) {
			cout << i+1 << " ";
		}
		cout << endl;

		//Prompt the user where to shoot
		int shootAt;
		getRoomToShootAt:
		cout << "Which room would you like to shoot at?";
		cin >> shootAt;

		//Check if input is valid
		if (shootAt < 1 || shootAt > roomCount) {
			cout << "invalid" << endl;
			cin.clear();
			cin.ignore(10, '\n');
			goto getRoomToShootAt;
		}
		shootAt--;
		bullets--;


		//Display the current zombie distribution in this format:
		//E E Z E Z
		//1 2 3 4 5 
		displayField(rooms, roomCount, zombies, zombieCount);

		//Stun all zombies in the room the player shot at (point them to an outside location)
		for (int i = 0; i < zombieCount; i++) {
			if (zombies[i] == &rooms[shootAt]) {
				zombies[i] = stunnedZombiesLocation;
			}
		}
		cout << "\n" << endl;

		//Count the active zombies left, and tell the player
		activeZombies = countActiveZombies(zombies, zombieCount, stunnedZombiesLocation);
		if (activeZombies == 1) {
			cout << "There is only 1 zombie left unstunned." << endl;
		} else {
			cout << "There are " << activeZombies << " zombies left unstunned." << endl;
		}

		//Check win/lose If the player is out of bullets, they lose. If the all zombies are stunned, they win
		for (int i = 0; i < zombieCount; i++) {
			if (countActiveZombies(zombies, zombieCount, stunnedZombiesLocation) == 0) {
				win = true;
				play = false;
			}
		}
		if (bullets <= 0) {
			cout << "Oh no, you ran out of bullets! Your brains are now getting eaten!" << endl;
			play = false;
			win = false;
		}
	}

	//Report sucess or failure
	string winMessage = "You won! Congratulations!";	
	string loseMessage = "Game Over";
	if (win)
		cout << winMessage;
	else
		cout << loseMessage;

	return 0;
}