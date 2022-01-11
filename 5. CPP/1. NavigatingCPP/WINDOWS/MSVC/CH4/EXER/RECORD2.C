// record2.C - object lifetime problems with member references
#include <iostream.h>
#include "Record2.h"

int main()
{
	StringN *p1 = new StringN(4, "\0\01\02\0");
	StringN *q1 = new StringN(6, "block1");
	Record R1("header", *p1, *q1);

	StringN *p2 = new StringN(6, "\0\21\22\23\24\0");
	StringN *q2 = new StringN(6, "block2");
	Record R2("packet", *p2, *q2);

	//delete p1;  delete q1;			// deleting could cause problems
	//delete p2;  delete q2;			// deleteing could cause problems

	R1.print();
	R2.print();
	return 0;
}

/**********************************************************************

$ record2
header : \0\01\02\0 : block1
packet : \0\021\022\023\024\0 : block2

1.  This version of Record uses references for field1 and field2.

2.  References are risky because of object lifetimes.
	 Because we store references inside Records instead of objects, both
	 field members are invalid after users delete them.
	 It is safer, therefore, to make the fields StringN objects.

3.  If you uncomment the delete statements above, this program may
	 produce garbage results.

*/
