// record.C - containment and member initialization
#include <iostream.h>
#include "Record.h"

int main()
{
	try {
		Record R1("header", 4, "\0\01\02\0", 6, "block1");
		Record R2("packet", 6, "\0\21\22\23\24\0", 6, "block2");

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

$ record 
header : \00\01\02\00 : block1
packet : \00\021\022\023\024\00 : block2

*/
