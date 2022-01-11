// zip3.c - Assoc lvalue and rvalue
#include <iostream.h>
#include "Assoc2.h"
#include "String.h"

int main()
{
	Assoc<String, long> z(10);					// map 10 Strings to 10 longs
	cout << "Input an integer: ";
	//cin >> z["aja"];							// lvalue or rvalue?

	long num;										// Here's the solution
	cin >> num;										// input to an long
	z["aja"] = num;								// assign to Assoc element
	cout << z << endl;							// display element
	return 0;
}

/**********************************************************************

$ zip3
Input an integer: 456
0 : aja : 456

NOTES:
	1. The first cin statement does not compile because of 
		overloaded operator>>() ambiguities.

	2. This cin statement is a "gotcha" because it's treated like 
		an rvalue, but we really need an lvalue for cin, so that it
		may change its value.

	3. The solution is to use cin with an long and store the 
		input long into the Assoc element as an lvalue.

*/
