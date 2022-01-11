// invest4.c - Investment class, dynamic_cast, QStock, references
#include <iostream.h>
#include "Invest4.h"

int main()
{
	try {
		 QStock s1(100, 15.5);
		 Stock s2(100, 20);
		 Land m(10000);

		 if (buy(s1, s2))
			 cout << "buy it" << endl;

		 if (buy(s1, m))							// throws exception
			 cout << "buy it" << endl;
	}
	catch (const InvestmentError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**************************************************************************

$ invest4
Stock::dividend()
QStock::dividend()
buy it
Investment: argument must be a Stock

*/
