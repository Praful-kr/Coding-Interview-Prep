/*POLYMORPHISM : ability of a message to be displayed in more than one form.
	-->Types:
		1. Compile time
			1a. Function overloading(functions with same name and different types/number of arguments)
			1b. Operator overloading(overloading an operator to perform different functionality. eg. using '+' operator to add complex numbers)
		2. Run time(achieved by virtual functions)
			during inheritance if base class and child class have same function then we use virtual keyword.


*/

#include<iostream>
using namespace std;

//Function overloading
class A {
public:
	void fun() {
		cout << "No arguments \n";
	}
	void fun(int x) {
		cout << "with int \n";
	}
	void fun(double x) {
		cout << "with double \n";
	}
};

//Operator overloading
class Complex {
	int real, imag;
public:
	Complex(int r = 0, int i = 0) {
		real = r;
		imag = i;
	}
	Complex operator + (Complex const &obj) {
		Complex res;
		res.imag = imag + obj.imag;
		res.real = real + obj.real;
		return res;
	}
	void display() {
		cout << real << " + i" << imag << endl;
	}

};

//Function overriding
class Base {
public:
	virtual void print() {						//virtual keyword used to obtain runtime polymorphism
		cout << "Base class print function\n";
	}
	void display() {
		cout << "Base class display function\n";
	}
};

class Derived : public Base {
public:
	void print() {
		cout << "Derived class print function\n";
	}
	void display() {
		cout << "Derived class display function\n";
	}

};

int main() {

	A a;					//Function overloading
	a.fun();
	a.fun(1);
	a.fun(1.0);

	Complex c1(12, 7), c2(6, 7);		//Operator overloading
	Complex c = c1 + c2;
	c.display();

	Base *baseptr;						//function overriding
	Derived d;
	baseptr = &d;
	baseptr->print();
	baseptr->display();

	Base b;
	Derived d1;
	b.print();
	b.display();
	d1.print();
	d1.display();

	return 0;
}