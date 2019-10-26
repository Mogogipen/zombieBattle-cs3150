using namespace std;

//*****Function header file for zombie battle*****\\

#ifndef FUNCTIONS
#define FUNCTIONS

//Required functions
char* placeZombieInRoom(char*, char*, int);
void displayField(char*, int, char**, int);
int countActiveZombies(char**, int, char*);

//Other functions
void randomizeZombies(char**, char*, int, int, int, char*);
bool isValidInteger(int);
int power(int, int);
void clrScrn();

#endif