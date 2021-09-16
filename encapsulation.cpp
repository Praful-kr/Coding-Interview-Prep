/*				ENCAPSULATION
	--> Hiding "sensitive" data from the user
		eg. driving a car doesn't require you to know the working of the engine for the user
	--> How this is achieved?
		through private access specifier(i.e. outside classes can't access it)
	--> Data members and member functions can be accessed within the class/outside the class/ by inherited class.
	--> These controls to access are given by access modifiers: Public, Private, Protected
		-> Public: Objects can access the data members and member functions even outside the class
		-> Private: Objects cannot access the data members and member functions outside the class. These can be accessed only inside the class
		-> Protected: Objects cannot access the data members and member functions outside the class. These can be accessed only inside the class and inherited class
	--> Advantages of encapsulation:
		-> Good coding practice, useful in interviews
		-> increased security of data
*/

#include<iostream>
using namespace std;

class A {
public:
	int a;
	void funcA() {
		cout << "Function A \n";
	}
private:
	int b;
	void funcB() {
		cout << "Function B \n";
	}
protected:
	int c;
	void funcC() {
		cout << "Function C \n";
	}
};

int main() {
	A obj;
	obj.funcA();		//will run without error as it is accessing public data
	obj.funcB();		//will give error as it is accessing private dat
	a	return 0;
}
