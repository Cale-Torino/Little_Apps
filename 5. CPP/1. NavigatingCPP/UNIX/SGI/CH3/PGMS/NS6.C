// ns6.C - local using directives inside namespace definitions
#include <iostream.h>

namespace Black {							// define namespace Black
	int j;
	void print(int);
	char ch;
}

void Black::print(int k) { 
	cout << "Black::print() = " << k << endl;
}

namespace Grey {							// define namespace Grey
	using namespace Black;				// local using directive
	int j;									// separate from Black::j
	double talk;
}

namespace Black {							// namespace extension
	bool contrast;
}

void sub3() {
	using namespace Grey;				// local using directive
	print(5);								// legal, Black::print()
	ch = 'a';								// legal, Black::ch
	talk = 5.67;							// legal, Grey::talk
	//j = 22;								// illegal, Black::j or Grey::j?
	Black::j = 22;							// legal, Black::j
	contrast = true;						// legal, Black::contrast
	cout << "sub3: " << ch << ' ' << talk << ' ' << contrast << endl;
}

int main()
{
	sub3();
	return 0;
}

/************************************************************************

$ ns6
Black::print() = 5
sub3: a 5.67 1

*/
