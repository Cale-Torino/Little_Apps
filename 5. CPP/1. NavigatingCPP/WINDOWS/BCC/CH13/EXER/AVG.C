// avg.c - Double class with exception objects
#include <iostream.h>
#include "Double.h"

int main()
{
	try {
		Double a = 12, b = 6, c = 0;
		cout << a/b << endl;
		cout << 18.5/b << endl;
		cout << a/c << endl;
	}
	catch (const DivideByZero & e) {
		e.response();
		return 1;
	}
	return 0;
}

/********************************************************

$ avg
2
3.08333
Double: divide by zero with numerator 12

NOTES:
	1. The Double class throws an exception when the / and /= operators have
		denominators that are zero.

	2. In Double.h, there are two versions of operator/=() in the Double class. 
		One version is a member function and the other is a non-member friend. 

	3. Two versions of operaotr/=() handles symmetry of operands and disallows 
		constants as left operands. Both functions call a private divide() function 
		that detects zero denominators and throws DivideByZero exceptions.

*/
