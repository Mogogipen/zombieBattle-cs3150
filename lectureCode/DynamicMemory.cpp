//Dynamic Memory Allocation in C++
//10-14-19
//Dr. G

#include <iostream>

using namespace std;

int main()
{
	//What does the following statement do?
	//Answer in terms of heap/stack.
	float tm;
	
	//What does this statement do?
	float* m;
	
	//Explain this output
	// cout << "m = " << m << endl;
	// cout << "*m = " << *m << endl;
	cout << "\n\n\n*************************************\n\n\n"<<endl;
	
	//This part should be review
	float n = 3.14;
	m = &n; 
	cout << "the contents of m are " << *m <<endl;
	*m = 7.894;
	cout << "n now holds " << n << endl;
	cout << "\n\n\n*************************************\n\n\n"<<endl;
	
	//Now we will explore "new"
	float* o;
	//Try these lines and see what happens
	//cout << "o = " << o << endl;
	//cout << "*o = " << *o << endl;
	
	cout << "\nUsing new now\n\n";
	
	o = new float;
	
	//at this point there's still nothing predictable in it
	//where's the memory pointed to be o?
	cout << "o = " << o << endl;
	cout << "*o = " << *o << endl;
	
	o = new float(7.894);
	//What's the difference in the above and *o = 7.894?
	
	cout << "*o = " << *o << endl;
	cout << "\n\n\n*************************************\n\n\n"<<endl;
	
	//Whats the difference in declaring a variable and dynamic memory allocation?
	
	//If you create it, you should destroy it.
	
	delete o;
	
	cout << "o = " << o << endl;
	cout << "*o = " << *o << endl;
	
	//Any idea why the above still prints?
	
	cout << "\n\n\n*************************************\n\n\n"<<endl;
	
	float *q = new float(6.78);
	
	cout << "q = " << q << endl;
	cout << "*q = " << *q << endl;
	
	cout << "o = " << o << endl;
	cout << "*o = " << *o << endl;
}