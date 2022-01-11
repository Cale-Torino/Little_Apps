// ns5.C - local using directives inside functions
#include <iostream.h>

namespace Black {						// define namespace Black
	int j;
	void print(int);
	char ch;
}

void Black::print(int k) { 
	cout << "Black::print() = " << k << endl;
}

namespace White {						// define namespace White
	int j;
	void print(int);
	double vision;
}

void White::print(int k) { 
	cout << "White::print() = " << k << endl;
}

int j;									// global j

void sub3() {
	using namespace Black;				// local using directive for Black
	using namespace White;				// local using directive for White
	//j = 0;									// illegal, White::j, Black::j, or ::j?
	//print(5);								// illegal, Black or White print()?
	ch = 'a';								// legal, Black::ch
	vision = 7.65;							// legal, White::vision
	cout << "sub3: " << ch << ' ' << vision << endl;
}

void sub4() {
	using namespace Black;				// local using directive for Black
	using namespace White;				// local using directive for White

	int j = 10;								// local j, hides White::j and Black::j
	::j = 5;									// legal, global j
	White::j = 5;							// legal, White::j
	Black::print(j);						// legal, Black::print, local j
	cout << "sub4: " << ::j << ' ' << White::j << endl;
}

int main()
{
	sub3();
	sub4();
	return 0;
}

/************************************************************************

$ ns5
sub3: a 7.65
Black::print() = 10
sub4: 5 5

*/
