// invest.C - Investment class, no RTTI
#include <iostream.h>
#include "Invest.h"

int main()
{
	Stock s;
	tax(&s);												// pass Stock Investment

	Land m;
	tax(&m);												// pass Land Investment
	return 0;
}

/**************************************************************************

$ invest
Stock::purchase()
Land::purchase()

*/
