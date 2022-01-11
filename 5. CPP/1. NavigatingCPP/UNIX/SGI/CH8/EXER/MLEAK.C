// mleak.C - memory leak detector, bad delete addresses
#include <iostream.h>
#include <stdlib.h>
#include "New.h"

class A {
public:
	A() { cerr << "A constr(object): " << this << endl; }
	~A() { cerr << "A destr(object): " << this << endl; }
};

int main() 
{
	try {
		 atexit(mleak_check);					// check for memory leaks at exit
		 char *pc = "hello";						// pointer to char
		 cout << "char ptr = " << (void *)pc << endl;

		 A *p1 = New A;							// create A object
		 Delete p1;									// release A object
		 Delete pc;									// bad free store address
	}
	catch (const NewError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ mleak 
char ptr = 0x100122d0
A constr(object): 0x10013538
A destr(object): 0x10013538
Attempt to delete bad free store pointer: 
	Filename: mleak.C
	Line Number: 21
	Pointer address: 0x100122d0

NOTES:
	1. The changes are implemented in New.h and New.C.

	2. In New.h, we introduce a Delete macro which calls a deletep() function before
		calling operator delete. The arguments to deletep() are __FILE__ and __LINE__,
		the filename and line number of the call to delete.  This function is activated 
		when -DMLEAK is defined.  

	3. In New.C, the deletep() function saves the __FILE__ and __LINE__ in fname_delete
		and lineno_delete to pinpoint the calls to operator delete.
		Inside operator delete(), if we do not find the allocated free store address in 
		the plist array, we display the bad address information which includes the spot 
		where the call was made.

	4. Note: your system may call the global operator delete to free its own pointers.
		In this case, you will see a list of "bad" pointers displayed, even though they
		were not addresses you created with operator new.

*/
