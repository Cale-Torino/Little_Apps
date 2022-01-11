// unnamed2.C - global scope vs. unnamed scope
#include <iostream.h>

namespace {							// unnamed namespace
	const int Max = 20;
	char buffer[Max];
	int counter;
}

void sub1() {
	buffer[0] = 'x';				// legal, unnamed member
	cout << buffer[0] << endl;
	counter = 3;					// legal, unnmaed member
	cout << counter << endl;
}

int counter = 1;					// legal, global variable

void sub2() {
	//counter++;					// illegal, ambiguous (global or unnamed)?
	::counter = 5;					// legal, global 
	int counter = 0;				// legal, hides global and unnamed member
	counter = 10;					// legal, local variable
	cout << "counter = " << counter << ", ::counter = " << ::counter << endl;
}

int main()
{
	sub1();
	sub2();
	return 0;
}

/************************************************************************

$ unnamed2
x
3
counter = 10, ::counter = 5

*/
