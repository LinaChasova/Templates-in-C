#include <iostream>
#include <string>
using namespace std;

class example {	//user-defined type with two attributes: int and string
public:
	int f;
	string s;
	example();	//default construct

	example(int a_f, string a_s) : f(a_f), s(a_s)	//special construct
	{}

	bool operator < (example& example)	//finds the smallest int attribute of two example objects
	{
		return f < example.f;
	}

	bool operator > (example& example)	//finds the biggest int attribute of two example objects
	{
		return f > example.f;
	}

	example operator += (int n)	//function for += operator (adds int attribute to the int)
	{
		f = f + n;
		return *this;
	}

	example operator -= (int n)	//function for -= operator (subtracts int from int attribute)
	{
		f = f - n;
		return *this;
	}

	friend ostream& operator << (ostream& out, const example& e)	//function to print class example
	{
		out << "f = " << e.f << ", s = " << e.s;
	}

};

/*
	please, consider using classes 
	that have '>', '<', "+=", "-=" operators
*/
template <typename T>
void alignArray (T* array, int size, T barrier)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] < barrier) array[i] += 2;
		else if (array[i] > barrier) array[i] -= 2;
	}
}

int main()
{
	example array[] = { example (4, "a") , example (10, "b"), example (3, "c"), example (5, "d")}, barrier(4, "fff");	//initializing an array
	cout << "original array:" << endl;
	for (int i = 0; i < 4; i++)	//printing the original array
		cout << array[i] << endl;
	alignArray(array, 4, barrier);	//changing the array with template function
	cout << endl << "changed array: " << endl;
	for (int i = 0; i < 4; i++)	//printing the changed array
		cout << array[i] << endl;
}

