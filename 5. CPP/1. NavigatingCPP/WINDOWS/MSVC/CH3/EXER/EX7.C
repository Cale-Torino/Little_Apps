// ex7.c - character pointers, storage classes
#include <iostream.h>

int main()
{
	char *ps1 = "hello";
	char **ps2 = new char *("hello");

	cout << ps1 << endl;								// displays hello
	cout << *ps2 << endl;							// displays hello

	delete ps2;
	return 0;
}

/********************************************************************

$ ex7
hello
hello

Notes:

1.  ps1 and ps2 live on the stack.
2.  Both "hello" strings live in the data area.
3.  ps2 is a pointer to a free store pointer, initialized to "hello".
4.  The compiler releases ps1 at the end of a block, whereas the
	 programmer releases ps2 with a delete;  hence, there is more
	 control over the run-time environment with ps2 than with ps1.

*/
