// bound.c - Generic Bounded Array objects
#include <iostream.h>
#include "BArray.h"
#include "String.h"

template <class TYPE>
void fill(BArray<TYPE> & a, const TYPE *val) {
	int idx = 0;
	for (int i = a.lb(); i <= a.ub(); i++)
		a[i] = val[idx++];
}

int main()
{
	try {
		BArray<int> a(10, 15);						// integer BArray
		static int inums[] = { 1, 2, 3, 4, 5, 6 };
		fill(a, inums);
		cout << a << endl;

		BArray<int> b(10, 15);						// integer BArray
		b = a;											// BArray assignment
		cout << b << endl;

		BArray<String> s(10, 15);					// String BArray
		static String snums[] = { "one","two","three",
			"four","five","six" };
		fill(s, snums);
		cout << s << endl;

		BArray<String> t = s;						// BArray copy initialization
		cout << t << endl;
		t[9] = "bogus";								// out of bounds
	}
	catch (const ArrayError & e) {
		e.response();									// virtual call
		return 1;
	}
	return 0;
}

/*****************************************************************************

$ bound
1 2 3 4 5 6 
1 2 3 4 5 6 
one two three four five six 
one two three four five six 
BArray: subscript 9 out of bounds for lower = 10, upper = 15

*/
