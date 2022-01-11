// catch3.c - catch exception objects by value
#include <iostream.h>
#include "Fraction.h"

void do_process(int n) {
	try {
		throw FractionError(n);					// throw exception object
	}
	catch (const FractionError err) {		// catch by value - BAD
		err.response();
	}
}

int main()
{
	int val = 12;
	do_process(val);
	return 0;
}

/**********************************************************************

$ catch3 
Zero denominator for numerator 12

*/
