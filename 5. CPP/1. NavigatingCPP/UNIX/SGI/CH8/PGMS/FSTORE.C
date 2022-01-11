// fstore.C - customized New for debugging
#include "Newd.h"

int main()
{
	try {
		int *ip1 = New int;
		int *ip2 = New int[100000000L];				// big chunk...
		//int *ip2 = New int[65535];
		delete ip1;
		delete [] ip2;
	}
	catch (const NewError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ CC -DNEW fstore.C -o fstore
$ fstore 
fstore
file fstore.C - line 8: new error for 400000000 bytes

*/
