// s1.C - StringN objects
#include <iostream.h>
#include "StringN.h"

int main()
{
	try {
		StringN s1(10, "goodbye\013\014\015");
		StringN s2(12, "\0two nulls\0\n");
		StringN s3 = s2;

		s1.print(); cout << endl;
		s3.print();
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
\00two nulls\00
22 characters

*/
