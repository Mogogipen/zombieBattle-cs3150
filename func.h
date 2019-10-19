using namespace std;

//*****Function header file for zombie battle*****\\

#ifndef FUNCTIONS
#define FUNCTIONS

//Required functions
void placeZombieInRoom(char*, char*, int);
void displayField(char*, int, char**, int);
int countActiveZombies(char**, int, char*);

//Other functions
bool isValidInteger(int);
int power(int, int);

#endif