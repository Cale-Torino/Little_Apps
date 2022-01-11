// invest2.c - Investment class, dynamic_cast
#include <iostream.h>
#include "Invest2.h"

int main()
{
	Stock s;
	tax(&s);												// pass Stock Investment

	Land m;
	tax(&m);												// pass Land Investment
	return 0;
}

/**************************************************************************

$ invest2
Stock::purchase()
Stock::dividend()
Land::purchase()

*/
