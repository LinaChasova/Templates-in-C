#include <iostream>
#include <string>
using namespace std;

class Person 	//user-defined type class Person with 2 attributes
{
public:
	string name;	//name of the Person
	int age;		//agw of the Person

	bool operator > (Person& Person)	//function to know the older Person
	{
		return age > Person.age;
	}

	friend ostream& operator<<(ostream& out, const Person& p)	//function to print the class Person
	{
		out << p.name << " Age:" << p.age;
		return out;
	}
};

/*
	please, consider using classes that have the '>' operator
*/
template <typename T>	//template to find Maximum of two objects
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 15, b = 4;
	double a1, b1;
	Person teacher, student, result;
	teacher.name = "Alex";
	teacher.age = 40;
	student.name = "Mary";
	student.age = 17;
	cout << "Comparing two integers: " << a << " " << b << endl << "The max is:" << endl << Max(a, b) << endl;	//find Maximum of two integers
	cout << "PLease print in two doubles:" << endl;
	cin >> a1 >> b1;
	cout << "The max is:" << endl << Max(a1, b1) << endl;	//find Maximum of two doubles
	cout << "Comparing two persons: " << teacher << "; " << student << endl;
	cout << "The older person is: " << endl << Max(teacher, student) << endl;	//find Maximum of two Person's objects (the older Person)
	return 0;
}