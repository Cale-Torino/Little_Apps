// pd3.c - private derivation is correct for BArray
#include <iostream.h>
#include "Array.h"
#include "BArray.h"

template <class TYPE>
void calc(Array<TYPE> & a) {
	int i = 55;
	a[i] = 11;
}

int main()
{
	try {
		 Array<int> a(10);						// Array of 6 integers
		 calc(a);

		 BArray<int> b(10, 15);					// BArray of 6 integers
		 //calc(b);									// illegal, not subtype
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ pd3 
Array: subscript 55 out of bounds, max subscript = 9

*/
