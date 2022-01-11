// zip.C - associative arrays with lvalue/rvalue separation
#include <iostream.h>
#include "Assoc.h"
#include "String.h"

int main()
{
	try {
		 Assoc<String, long> zip(6);						// map String to integer
		 cout << "length of zip array is " << zip.length() << endl;

		 zip["paul"] = 92024;								// assign zipcode
		 zip["steve"] = 92119;								// assign zipcode
		 zip["tom"] = 92019;									// assign zipcode
		 cout << "tom's zipcode is " << zip["tom"] << endl;

		 Assoc<String, long> num1(6);						// Assoc array
		 num1 = zip;											// Assoc assignment
		 
		 const Assoc<String, long> num2 = num1;		// copy initialization
		 cout << num2 << endl;								// display Assoc array
		 cout << num2["fritz"] << endl;					// error, no entry
	}
	catch (const AssocError<String, long> & e) {
		e.response();											// error message
		return 1;
	}
	return 0;
}

/******************************************************************

$ zip
length of zip array is 6
tom's zipcode is 92019
0 : paul : 92024
1 : steve : 92119
2 : tom : 92019

Assoc: could not find "fritz"

*/
