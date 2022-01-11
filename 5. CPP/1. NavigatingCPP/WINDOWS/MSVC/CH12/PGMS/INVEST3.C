// invest3.c - Investment class, dynamic_cast, QStock
#include <iostream.h>
#include "Invest3.h"

int main()
{
	QStock s;
	tax(&s);												// pass Stock Investment
	audit(&s);											// pass Stock Investment

	Land m;
	tax(&m);												// pass Land Investment
	return 0;
}

/**************************************************************************

$ invest3
QStock::purchase()
QStock::dividend()
QStock::dividend()
Land::purchase()

*/
