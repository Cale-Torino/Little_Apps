// invest1.c - Investment class
#include <iostream.h>
#include "Invest1.h"

int main()
{
	Stock s;
	tax(&s);												// pass Stock Investment

	Land m;
	tax(&m);												// pass Land Investment
	return 0;
}

/**************************************************************************

$ invest1
Stock::purchase()
Land::purchase()

*/
