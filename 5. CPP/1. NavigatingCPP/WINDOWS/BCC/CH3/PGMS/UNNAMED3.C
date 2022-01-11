// unnamed3.c - unnamed namespace extensions
#include <iostream.h>

namespace {								// unnamed namespace
	int j;
	void print(int);					// prototype
}

namespace {								// append to same unnamed namespace
	void print(int i) { cout << i << endl; }
}

void sub() {
	j = 3;
	print(j);							// no ambiguity
}

int main()
{
	sub();
	return 0;
}

/************************************************************************

$ unnamed3
3

*/
