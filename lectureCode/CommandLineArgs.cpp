//Command line arguments demonstration
//10-14-2019
//Dr. G

#include <iostream>

using namespace std;

//Typical declaration. No surprises here. 
//What does this mean anyways?
//int main(){}

//Another way to declare main. 
//What does this mean

// int main(int argc, char* argv[])
// {
// 	cout << argc << endl;
// 	//cout << argv[0] << endl;
	
// 	//for (int x = 0; x < argc; x++)
// 	//	cout << argv[x] << endl;
// }

// Alternatively
int main(int argc, char** argv)
{	
	for (int x = 0; x < argc; x++)
		cout << argv[x] << endl;
}

// //What is each element of argv?
// //How do you get ints and floats from this?

// int main(int argc, char* argv[])
// {
// 	//int x = argv[1];
// 	//cout << x << endl;
// }
