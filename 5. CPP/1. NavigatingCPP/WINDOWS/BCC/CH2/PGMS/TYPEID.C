// typeid.c - typeid operator
#include <iostream.h>
#include <typeinfo.h>

int main()
{
	char c = 'a';										// char
	int d = 13;											// int
	cout << (typeid(c) == typeid(char) ?		// compares types and
			"same" : "different") << endl;		// displays "same"
	cout << (typeid(c) != typeid(d) ?			// compares types and
			"different" : "same") << endl;		// displays "different"
	cout << (typeid(c+d) == typeid(int) ?		// compares types and
			"int" : "char") << endl;				// displays "int"
	cout << c << ' ' << d << endl;
	return 0;
}

/**********************************************************************

$ typeid
same
different
int
a 13

*/
