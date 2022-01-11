// record2.C - containment and member initialization with references
#include <iostream.h>
#include "Record2.h"

int main()
{
	try {
		 StringN S1(4, "\0\01\02\0");
		 StringN S2(6, "block1");
		 Record R1("header", S1, S2);

		 StringN S3(6, "\0\21\22\23\24\0");
		 StringN S4(6, "block2");
		 Record R2("packet", S3, S4);

		 R1.print();
		 R2.print();
	}
	catch (const StringNError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ record2 
header : \00\01\02\00 : block1
packet : \00\021\022\023\024\00 : block2

*/
