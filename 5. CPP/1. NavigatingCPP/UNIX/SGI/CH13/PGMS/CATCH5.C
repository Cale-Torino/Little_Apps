// catch5.c - catch exception objects by reference
#include <iostream.h>
#include "Fraction.h"

void do_process(int n) {
	try {
		throw FractionError(n);					// throw exception object
	}
	catch (const FractionError & err) {		// catch by reference - OK
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

$ catch5
Zero denominator for numerator 12

*/
