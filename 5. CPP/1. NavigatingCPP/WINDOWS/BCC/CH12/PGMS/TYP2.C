// typ2.c - typepid(), polymorphic types
#include <iostream.h>
#include <typeinfo.h>
#include "Invest5.h"

int main()
{
	Investment *pi = new Stock;						// pointer to Investment
	Investment & ri = *pi;								// reference to Investment

	cout << "typeid() with pointers" << endl;
	cout << (typeid(pi) == typeid(Investment *)) << endl;		// true (static)
	cout << (typeid(pi) == typeid(Stock *)) << endl;			// false (static)
	cout << (typeid(pi) == typeid(Investment)) << endl;		// false (static)
	cout << (typeid(pi) == typeid(Stock)) << endl;				// false (static)
	cout << (typeid(*pi) == typeid(Stock)) << endl;				// true (dynamic)

	cout << "typeid() with references" << endl;
	cout << (typeid(*pi) == typeid(Investment)) << endl;		// false (dynamic)
	cout << (typeid(ri) == typeid(Stock)) << endl;				// true (dynamic)
	cout << (typeid(ri) == typeid(Investment)) << endl;		// false (dynamic)
	cout << (typeid(&ri) == typeid(Investment *)) << endl;	// true (static)
	cout << (typeid(&ri) == typeid(Stock *)) << endl;			// false (static)
	delete pi;
	return 0;
}

/***************************************************************************

$ typ2 
typeid() with pointers
1
0
0
0
1
typeid() with references
0
1
0
1
0

*/
