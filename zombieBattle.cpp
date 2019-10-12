#include <iostream>
#include <string>
#include "func.h"
#include "const.h"

using namespace std;

//*****This is a zombie killing game! (main cpp file)*****\\

int main()
{

//1. accept as command line inputs: number of rooms, max number of zombies, and zombie 
//regeneration rate

//2. Gather command line input and verify they entered enough arguments and that there are 
//more rooms than zombies

//3. Create a dynamic character area to represent the rooms and initialize the area to 
//all 'E's

//4. Create an array of char pointers to represent the zombies. Array will be the max 
//number of zombies

//5. Randomly point zombies at rooms array. When a zombie points at a room space change 
//the letter in the array to Z. Remember, because we are using pointers you can have more than one
//zombie in a room. 

//6. Start game loop

//7. Display rooms as '*' place numbers underneath so the user can easily see where they 
//can shoot. Ex

//* * * * * * *
//1 2 3 4 5 6 7

//8. Prompt user to pick a room to "shoot" in. 

//9. Reveal the current zombie distribution. Example: E E Z E E Z Z E E. 

//10.  Check to see if and how many zombies pointed at that room. Point all zombies that 
//were in that room to the "stunned" constant. 

//11. Report zombies left and change all rooms to 'E.'

//12. Cycle through the zombie pointer array. Point each zombie at a new random location 
//unless it is stunned. For each stunned zombie offer a chance of regeneration based on 
//the regeneration rate. For example, 3 would indicate a 3% chance it would regenerate. 
//(You can do this by selecting a random number from 1 to 100.)

//13. If all zombies are stunned, terminate loop

//14. End game loop

//15. Report success


	return 0;
}