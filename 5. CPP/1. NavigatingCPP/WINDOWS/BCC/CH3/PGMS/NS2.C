// ns2.c - namespace extensions
#include <iostream.h>

namespace Blue {						// original namespace definition
	int j;
	void print(int);
}

void Blue::print(int k) { 
	cout << "Blue::print() = " << k << endl;
}

namespace Blue {						// namespace extension
	char ch;
	char buffer[20];
}

namespace BigBlue {					// equivalent to the above
	int j;
	void print(int);
	char ch;
	char buffer[20];
}

int main()
{
	Blue::j = 0;
	Blue::print(5);
	Blue::ch = 'a';
	BigBlue::ch = 'z';
	int j = 10;							// legal, j is a local variable
	cout << j << endl;
	return 0;
}

/************************************************************************

$ ns2
Blue::print() = 5
10

*/
