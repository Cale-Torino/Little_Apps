// ns4.C - local using directives
#include <iostream.h>

namespace Blue {						// namespace definition
	int j;
	void print(int);
}

void Blue::print(int k) { 
	cout << "Blue::print() = " << k << endl;
}

void sub1() {
	using namespace Blue;			// local using directive
	j = 0;								// legal, Blue::j
	print(j);							// legal, Blue::print()
	cout << "sub1: " << Blue::j << endl;
}

void sub2() {
	//j = 1;								// illegal, j not declared
	//print(j);							// illegal, print() not defined
	cout << "sub2: " << Blue::j << endl;
}

int main()
{
	sub1();
	sub2();
	return 0;
}

/************************************************************************

$ ns4
Blue::print() = 0
sub1: 0
sub2: 0

*/
