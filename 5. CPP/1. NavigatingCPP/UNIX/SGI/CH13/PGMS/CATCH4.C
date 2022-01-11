// catch4.c - catch exception objects by address - dubious
#include <iostream.h>
#include "Fraction.h"

void do_process(int n) {
	try {
		FractionError *pe = new FractionError(n);		// create exception object
		throw pe;												// throw its address
	}
	catch (const FractionError *perr) {					// catch by address - BAD
		perr->response();
	}
}

int main()
{
	int val = 12;
	do_process(val);
	return 0;
}

/**********************************************************************

$ catch4 
Zero denominator for numerator 12

*/
