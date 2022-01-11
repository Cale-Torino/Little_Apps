// intarray.c - Integer Array class (non-generic)
#include <iostream.h>
#include "Array.h"

class IntArray : public Array<int> {
public:
	IntArray(int len) : Array<int>(len) { }
};

int main()
{
	try {
		 IntArray a(10);							// Array of 100 integers
		 cout << a.length() << endl;
		 a[5] = 111;
		 cout << a[5] << endl;
		 cout << a[55] << endl;
	}
	catch (const ArrayError & e) {
		e.response();								// virtual call
		return 1;
	}
	return 0;
}

/**********************************************************************

$ intarray 
10
111
Array: subscript 55 out of bounds, max subscript = 9

*/
