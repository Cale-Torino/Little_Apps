// newdata.c - template function for block allocation and initialization
#include <iostream.h>
#include "String.h"

template <class TYPE>
TYPE *new_data(int length, const TYPE & value) {
	TYPE *pd = new TYPE [length];				// calls default TYPE constructors
	for (int i = 0; i < length; i++)
		pd[i] = value;								// calls TYPE assignment
	return pd;
}

template <class TYPE>
void display(const TYPE *p, int length) {
	for (int i = 0; i < length; i++)
		cout << p[i] << ' ';
	cout << endl;
}

int main()
{
	int ival =0;	String sval = "abc";
	int *pi = new_data(10, ival);
	display(pi, 10);
	delete [] pi;										// must call, or memory leak

	String *ps = new_data(10, sval);
	display(ps, 10);
	delete [] ps;										// must call, or memory leak

	//double *pd = new_data(10, 0);				// error, instantiates integers
	//String *pt = new_data(10, "abc");			// error, char *, not String
	return 0;
}

/**********************************************************************

$ newdata 
0 0 0 0 0 0 0 0 0 0 
abc abc abc abc abc abc abc abc abc abc 

NOTES:
1. There are three reasons why the Block class is better than template
	function new_data() for allocating free store memory and initializing it.

	a. The user must call operator delete [] with the pointer address
		returned by new_data(); otherwise, memory leaks occur.
		The Block class destructor handles this implicitly.

	b. The new_data() function is inefficient. First, it calls
		operator new with a TYPE (which calls the TYPE default constructor) 
		before it assigns values.
		The Block class uses a pointer to a pointer to call operator new
		with an initial value directly.

	c. Conversion rules don't work with new_data() - (see above).
		The Block constructor handles conversions implicitly.

*/
