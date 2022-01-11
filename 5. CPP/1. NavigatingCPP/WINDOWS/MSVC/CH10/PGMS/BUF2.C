// buf2.C - Buffer objects
#include <iostream.h>
#include "Buffer.h"
#include "Array.h"

int main() 
{
	try {
		const int len1 = 5;
		const unsigned int len2 = 5;

		Buffer<int, len1> a;						// OK - constant int matches
		cout << a.length() << endl;

		//Buffer<int, len2> b;						// Error - no conversion

		Array<int> c(len1);							// OK - conversion
		Array<int> d(len2);							// OK - conversion
	}
	catch (const BufferError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ buf2 
5

*/
