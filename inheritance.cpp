/*				INHERITANCE
	--> it is possible to inherit attributes and methods from one class to another
		->DERIVED CLASS(PARENT): the class that inherits from another class
		->BASE CLASS(CHILD): the class being inherited from
	--> Types of inheritance:
		1. Single
		2. Multiple
		3. Multilevel
		4. Hybrid
		5. Heirarchical
	--> Inheritance rules:
		->
			class A {
    			public:
       				int x;
    			protected:
       				int y;
    			private:
       				int z;
			};

			class B : public A{
			    // x is public			// y is protected			// z is not accessible from B
			};

			class C : protected A{
			    // x is protected		// y is protected			// z is not accessible from C
			};

			class D : private A{			    // 'private' is default for classes
			    // x is private			// y is private				// z is not accessible from D
			};

		->
			-Everything that is aware of Base is also aware that Base contains publicMember.
			-Only the children (and their children) are aware that Base contains protectedMember.
			-No one but Base is aware of privateMember.
			(By "is aware of", I mean "acknowledge the existence of, and thus be able to access")

			next:
			The same happens with public, private and protected inheritance. Let's consider a class Base and a class Child that inherits from Base.

			-If the inheritance is public, everything that is aware of Base and Child is also aware that Child inherits from Base.
			-If the inheritance is protected, only Child, and its children, are aware that they inherit from Base.
			-If the inheritance is private, no one other than Child is aware of the inheritance.


*/

#include<iostream>
using namespace std;


// 1. Single Inheritance
class A {
protected:
	void func1() {
		cout << "Base A protected \n";
	}
public:
	void func() {
		cout << "Base A public \n";
	}
};

class B : public A {			//public and protected members of A are made public and protected members of class B respectively(inherited in B)

};

// 2. Multiple Inheritance
class C {
public:
	void funcC() {
		cout << "function in C \n";
	}
};
class D {
public:
	void funcD() {
		cout << "function in D \n";
	}
};
class E : public C, public D {
public:
};

//3. Multilevel Inheritance
class F {
public:
	void funcF() {
		cout << "Function in F \n";
	}
};
class G : public F {
public:
	void funcG() {
		cout << "Function in G \n";
	}
};
class H : public G {
public:
};

int main() {
	B b;
//	b.func1();
	b.func();

	E e;
	e.funcC();
	e.funcD();

	H h;
	h.funcF();
	h.funcG();

	return 0;
}