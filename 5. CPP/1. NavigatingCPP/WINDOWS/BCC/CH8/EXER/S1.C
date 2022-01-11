// s1.C - StringN objects with reference counts
#include <iostream.h>
#include "cStringN.h"

int main()
{
	try {
		cStringN s1(10, "goodbye\013\014\015");
		cStringN s2(12, "\0two nulls\0\n");
		cStringN s3 = s2;								// copy initialization
		cStringN s4;
		s4 = s3;											// assignment

		s1.print(); cout << endl;
		s3.print();
		s4.print();
		cout << s1.length() + s2.length() << " characters" << endl;
	}
	catch (const StringNError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ s1 
goodbye\013\014\015
\0two nulls\0
\0two nulls\0
22 characters

*/
