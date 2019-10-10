//ICE for pointers
//10-9-19
//Dr. G

#include <iostream>

using namespace std;

void zero(int&);


int main()
{
	int a = 0; 
	cout << a << endl;
	cout << &a << endl;
	//print out a
	//print out the memory location of a
	
	int& b = a;
	b++;
	cout << a << endl;
	//Change b to a reference variable that has the same location as a. 
	//Increment b, but print a. What happens?
	
	int c = 999; 
	zero(c);
	cout << endl << c << endl;
	//Alter zero() to pass by reference instead of pass by value and test it
	
	int d = 888;
	int* e = &d;
	cout << e << endl;
	cout << *e << endl;
	//Create a pointer e that points at d
	//Print e
	//print the contents of what it points at (dereference it)
	
	int** f = &e;
	//Create a pointer f that points at e
	//Uncomment the below and explain the output 
	
	cout << endl << d << endl << &d << endl;
	cout << endl << e << endl << *e << endl;
	cout << endl << f << endl << *f << endl << **f << endl;
		
	int array1 [] = {1,2,3,4,5,6,7,8,9};
	int* g = array1;
	for (int i = 0; i <= sizeof(g); i++) {
		cout << g[i];
	}
	cout << endl;
	//Create a pointer g and point it at array array1
	//iterate and print each element of the array using pointer g
	
	//Create a constant int h 
	//Create pointer to a constant and a constant pointer
	//Explain the difference syntactically and logically
	
	
	
}


void zero(int& x)
{
	x=0;
}

