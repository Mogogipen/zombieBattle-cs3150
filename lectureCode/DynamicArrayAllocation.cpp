//Dynamic Memory Allocation in C++ for arrays
//10-14-19
//Dr. G

#include <iostream>

using namespace std;

void printArray(int [], int);

int main()
{
	//Typical array declaration
	//What's actually happening it terms of stack/heap?
	int a[5];
	
	cout << a << endl;
	printArray(a, (sizeof(a)/sizeof(int)));
	
	int b[5] = {0,1,2,3,4};
	cout << b << endl;
	printArray(b, (sizeof(b)/sizeof(int)));
	
	cout << "\n\n\n*************************************\n\n\n"<<endl;
	
	//Dynamic memory allocation of an entire section of memory
	int *c;
	cout << c << endl;
	c = new int[5]; //how much memory is being allocated?
	for (int x = 0; x < 5; x++) c[x] = x;
	printArray(c, 5); //Why does this line work?
	
	cout << "\n\n\n*************************************\n\n\n"<<endl;
	
	//Explain the following
	cout << "c[0] = " << c[0] << endl;
	c++;
	cout << "c[0] = " << c[0] << endl;
	
	//delete c;
	delete[] c;

	cout << "here" << endl;
	
	//Why doesn't this work?
	// int d [5] = {0,1,2,3,4};
	// d++;
	
	//Why bother? Pros/Cons to memory allocation. 

}

void printArray(int temp [], int size)
{
	for (int x = 0; x < size; x++) cout << temp[x] << " ";
	cout << endl;
}