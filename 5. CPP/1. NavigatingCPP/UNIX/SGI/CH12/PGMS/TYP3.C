// typ3.c - typepid(), polymorphic types
#include <iostream.h>
#include "Invest5.h"

int main()
{
	Investment *p1 = new Stock;					// pointer to Investment
	Investment *p2 = new Land;						// pointer to Investment

	cout << p1->whattype() << endl;				// displays "Stock"
	cout << p2->whattype() << endl;				// displays "Land"

	Investment & r1 = *p1;							// reference to Investment
	Investment & r2 = *p2;							// reference to Investment

	cout << r1.whattype() << endl;				// displays "Stock"
	cout << r2.whattype() << endl;				// displays "Land"
	delete p1;		delete p2;
	return 0;
}

/**********************************************************************

$ typ3 
Stock
Land
Stock
Land

*/
