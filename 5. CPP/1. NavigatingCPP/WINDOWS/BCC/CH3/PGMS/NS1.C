// ns1.c - namespace definitions
#include <iostream.h>

namespace Red {					// define namespace Red
	int j;							// j is a member of namespace Red
	void print(int i)				// print() is a member of namespace Red
		{ cout << "Red::print() = " << i << endl; }
}

namespace Blue {					// define namespace Blue
	int j;							// j is a member of namespace Blue
	void print(int);				// print() is a member of namespace Blue
}

void Blue::print(int k) { 
	cout << "Blue::print() = " << k << endl;
}

void sub() {
	Red::j = 0;						// member of namespace Red
	Red::print(5);					// member of namespace Red
	//j = 5;							// illegal, no local j defined
	int j = 10;						// legal, j is a local variable
	Blue::j = 5;					// member of namespace Blue
	cout << j << endl;
}

int main()
{
	sub();
	return 0;
}

/************************************************************************

$ ns1
Red::print() = 5
10

*/
