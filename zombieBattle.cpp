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

	//1. accept as command line inputs: number of rooms, max number of zombies, and zombie 
	//regeneration rate

	cout << "Welcome to Zombie Splatter!!" << endl;

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

	//2. Gather command line input and verify they entered enough arguments and that there are 
	//more rooms than zombies

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

	//3. Create a dynamic character area to represent the rooms and initialize the area to 
	//all 'E's

	char* rooms = new char[roomCount];
	for (int i = 0; i < roomCount; i++) {
		rooms[i] = 'E';
	}

	//4. Create an array of char pointers to represent the zombies. Array will be the max 
	//number of zombies

	char* zombies[zombieCount];

	//5. Randomly point zombies at rooms array. When a zombie points at a room space change 
	//the letter in the array to Z. Remember, because we are using pointers you can have more than one
	//zombie in a room.

	srand(time(NULL));
	randomizeZombies(zombies, rooms, zombieCount, roomCount, regeneration, stunnedZombiesLocation);

	for (int i = 0; i < zombieCount; i++) {
		cout << rooms[i] << endl;
	}

	//6. Start game loop

	int loopCounter = 100; //If it reaches zero, it's game over, the player loses.
	bool play = true;
	bool win = false;
	int bullets = 25;
	int activeZombies;
	while (play) {

		//Tell the player how many bullets they have left

		cout << "You have " << bullets << " bullets left!" << endl;

		//7. Display rooms as '*' place numbers underneath so the user can easily see where they 
		//can shoot. Ex
		//* * * * * * *
		//1 2 3 4 5 6 7

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
		for (int i = 0; i < roomCount; i++) {
			cout << i+1 << " ";
		}
		cout << endl;

		//8. Prompt user to pick a room to "shoot" in. 

		int shootAt;
		getRoomToShootAt:
		cout << "Which room would you like to shoot at?";
		cin >> shootAt;
		if (shootAt < 1 || shootAt > roomCount) {
			cout << "invalid" << endl;
			cin.clear();
			cin.ignore(10, '\n');
			goto getRoomToShootAt;
		}
		shootAt--;
		bullets--;


		//9. Reveal the current zombie distribution. Example: E E Z E E Z Z E E. 

		displayField(rooms, roomCount, zombies, zombieCount);

		//10.  Check to see if and how many zombies pointed at that room. Point all zombies that 
		//were in that room to the "stunned" constant.

		for (int i = 0; i < zombieCount; i++) {
			if (zombies[i] == &rooms[shootAt]) {
				zombies[i] = stunnedZombiesLocation;
			}
		}
		cout << "\n" << endl;

		//11. Report zombies left and change all rooms to 'E.'

		activeZombies = countActiveZombies(zombies, zombieCount, stunnedZombiesLocation);
		if (activeZombies == 1) {
			cout << "There is only 1 zombie left unstunned." << endl;
		} else {
			cout << "There are " << activeZombies << " zombies left unstunned." << endl;
		}

		//12. Cycle through the zombie pointer array. Point each zombie at a new random location 
		//unless it is stunned. For each stunned zombie offer a chance of regeneration based on 
		//the regeneration rate. For example, 3 would indicate a 3% chance it would regenerate. 
		//(You can do this by selecting a random number from 1 to 100.)

		randomizeZombies(zombies, rooms, zombieCount, roomCount, regeneration, stunnedZombiesLocation);

		//13. If all zombies are stunned, terminate loop
		
		if (bullets <= 0) {
			play = false;
			win = false;
		}

		for (int i = 0; i < zombieCount; i++) {
			if (countActiveZombies(zombies, zombieCount, stunnedZombiesLocation) == 0) {
				win = true;
				play = false;
			}
		}

	//14. End game loop

	}

	//15. Report success

	string winMessage = "You won! Congratulation!";	
	string loseMessage = "Game Over";

	if (win)
		cout << winMessage;
	else
		cout << loseMessage;

	return 0;
}