// max3.c - max() template function, returns references
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline const TYPE & max(const TYPE & a, const TYPE & b) {
	return a > b ? a : b;
}

int main()
{
	String *ps = new String("abc");					// create "abc"
	String *pt = new String("xyz");					// create "xyz"

	const String & maximum = max(*ps, *pt);		// dangling reference

	delete ps;												// delete "abc"
	delete pt;												// delete "xyz"
	cout << maximum << endl;							// may not be correct
	return 0;
}

/**********************************************************************

$ max3 
xAH

*/
