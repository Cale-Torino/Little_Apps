// zip2.C - associative arrays with lvalue/rvalue separation, const
#include <iostream.h>
#include "Assoc.h"
#include "String.h"

void f(const Assoc<String, long> & z) {
	cout << "steve's zipcode is " << z["steve"] << endl;		// rvalue - OK
	//z["steve"]  = 80302;							// lvalue - compilation error
}

int main()
{
	try {
		 Assoc<String, long> zip(6);						// map String to integer
		 cout << "length of zip array is " << zip.length() << endl;

		 zip["paul"] = 92024;								// assign zipcode
		 zip["steve"] = 92119;								// assign zipcode
		 zip["tom"] = 92019;									// assign zipcode
		 cout << "tom's zipcode is " << zip["tom"] << endl;

		 Assoc<String, long> num1(6);						// map String to integer
		 num1 = zip;											// array assignment
		 const Assoc<String, long> num2 = num1;		// copy initialization
		 cout << num2 << endl;								// display names, zipcodes
		 //num2["bob"] = 93177;								// error, num2 is const
		 f(num2);
		 cout << num2["fritz"] << endl;					// error, name not in array
	}
	catch (const AssocError<String, long> & e) {		// catch handler
		e.response();											// display error message
		return 1;
	}
	return 0;
}

/******************************************************************

$ zip2
length of zip array is 6
tom's zipcode is 92019
0 : paul : 92024
1 : steve : 92119
2 : tom : 92019

steve's zipcode is 92119
Assoc: could not find "fritz"

*/
