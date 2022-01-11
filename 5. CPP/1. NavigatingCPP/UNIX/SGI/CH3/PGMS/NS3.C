// ns3.C - global using directives
#include <iostream.h>

namespace Blue {						// namespace definition
	int j;
	void print(int);
}

void Blue::print(int k) { 
	cout << "Blue::print() = " << k << endl;
}

using namespace Blue;				// using directive

void sub1() {
	j = 0;								// legal, Blue::j
	print(j);							// legal, Blue::print()
	cout << "sub1: " << Blue::j << endl;
}

void sub2() {
	j = 1;								// legal, Blue::j
	print(j);							// legal, Blue::print()
	cout << "sub2: " << Blue::j << endl;
}

void sub3() {
	j = 2;								// legal, Blue::j
	print(j);							// legal, Blue::print()

	int j = 10;							// legal, local j hides Blue::j
	Blue::j = 5;						// must qualify
	cout << "sub3: " << j << ' ' << Blue::j << endl;
}

int main()
{
	sub1();
	sub2();
	sub3();
	return 0;
}

/************************************************************************

$ ns3
Blue::print() = 0
sub1: 0
Blue::print() = 1
sub2: 1
Blue::print() = 2
sub3: 10 5

*/
