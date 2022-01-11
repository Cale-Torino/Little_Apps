// ns7.C - using declarations
#include <iostream.h>

namespace Black {						// define namespace Black
	int j;
	void print(int);
	char ch;
}

void Black::print(int k) { 
	cout << "Black::print(" << k << ')' << endl;
}

namespace White {						// define namespace White
	int j;
	void print(int);
	double vision;
}

void White::print(int k) { 
	cout << "White::print(" << k << ')' << endl;
}

using White::vision;						// global using declaration

void sub1() {
	using Black::print;					// local using declaration
	//ch = 'a';								// illegal, ch not defined
	vision = 7.65;							// legal, White::vision
	print(5);								// legal, Black::print()
}

void sub2() {
	//print(5);								// illegal, print() not defined
	vision = 3.45;							// legal, White::vision
	cout << "sub2: " << vision << endl;
}

void sub3() {
	using namespace White;				// local using directive
	using Black::print;					// local using declaration
	print(5);								// legal, Black::print()
	j = 2;									// legal, White::j
	using Black::j;						// local using declaration
	j = 3;									// legal, Black::j;
	//int j = 10;							// illegal, local j already defined
	cout << "sub3: " << j << endl;
}

int main()
{
	sub1();
	sub2();
	sub3();
	return 0;
}

/************************************************************************

$ ns7
Black::print(5)
sub2: 3.45
Black::print(5)
sub3: 3

*/
