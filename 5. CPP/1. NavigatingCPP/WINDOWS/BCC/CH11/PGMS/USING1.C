// using1.c - using declarations for dominance
#include <iostream.h>
#include "String.h"

class A {
public:
	void print(const String & str) {
		cout << "str = " << str << endl;
	}
};

class B : public A {
public:
	using A::print;					// bring into local scope
	void print(char ch) {			// overload print()
		cout << "char = " << ch << endl;
	}
};

void sub() {
	B b;
	b.print('z');						// OK
	b.print("Hello, world");		// OK, print() in local scope
}

int main()
{
	sub();
	return 0;
}

/******************************************************************

$ using1
char = z
str = Hello, world


*/
