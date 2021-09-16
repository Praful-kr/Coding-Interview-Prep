/*
	--> CLASS is a user defined datatype that is a blueprint containing some attributes and some functions
	--> OBJECTS are the instances of a class
	--> the data members of objects are accessed by using . operator
	--> private data members are accessible by the functions within the class
	--> CONSTRUCTORS are used to initialize values to the data members at the time of object creation
		-> CONSTRUCTORS have the same name as the CLASS
		-> if we define any parameterised constructor, then making a default constructor explicitely is compulsary
			(there will be error if we don not explicitely define a default constructor)
		-> DEFAULT COPY CONSTRUCTOR does shallow copy(stores references to objects to original memory address) and
		   when we define our own copy constructor deep copy happens(stores copy of the object's values)
*/

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class student {
	string name;

public:					//as it is by default private

	int age;
	bool gender;			//0->male, 1->female
	void setName(string s) {			//SETTER FUNCTION: to set(input) the value of private data member
		name = s;
	}
	void getName() {					//GETTER FUNCTION: to get(output) the value of private data member
		cout << "Name:" << name << endl;
	}
	void printInfo() {
//		cout << "Name: " << name << " ";
		getName();
		cout << "Age: " << age << endl;
		cout << "Gender: " << gender << endl;
	}

	student() {										//DEFAULT CONSTRUCTOR
		cout << "***DEFAULT CONSTRUCTOR***" << endl;
	}

	student(student &a) {
		cout << "***COPY CONSTRUCTOR***" << endl;
		name = a.name;
		age = a.age;
		gender = a.gender;
	}

	student(string s, int a, int g) {				//PARAMETERISED CONSTRUCTOR
		cout << "***PARAMETERISED CONTRUCTOR***" << endl;
		name = s;
		age = a;
		gender = g;
	}

	~student() {										//DESTRUCTOR
		cout << "***DESTRUCTOR CALLED***" << endl;
	}

	bool operator == (student &a) {						//OPERATOR OVERLOADING
		if (age == a.age && name == a.name && gender == a.gender)
			return true;
		return false;
	}
};

int main() {

// 	student a;
// 	a.setName("Praful");
// //	a.name = ;
// 	a.age = 25;
// 	a.gender = 0;

// 	student arr[3];
// 	for (int i = 0; i < 3; i++) {
// 		cout << "Enter name: ";
// 		string s;
// 		cin >> s;
// 		arr[i].setName(s);
// 		cout << "Enter age: ";
// 		cin >> arr[i].age;
// 		cout << "Enter gender: ";
// 		cin >> arr[i].gender;
// 	}

// 	for (int i = 0; i < 3; i++) {
//		cout << "Name: " << arr[i].getName();
// 		arr[i].printInfo();
// 	}
	student a("Praful", 25, 0);
//	a.getName();
//	a.printInfo();

	student b;

	student c(a);		//COPY CONSTRUCTOR(we can either call <  student c(a);  >    OR     <  student c = a;    >)
//	c.printInfo();

	if (c == a)							//OPERATOR OVERLOADING
		cout << "Same" << endl;
	else
		cout << "Not Same" << endl;

	return 0;
}