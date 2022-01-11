// block1.C - template Block class, specialized
#include <iostream.h>
#include "Block1.h"
#include "String.h"

template <class TYPE>
ostream & operator<<(ostream & os, const Block<TYPE> & b) {
	for (int i = 0; i < b.length(); i++)
		os << b[i] << ' ';
	return os;
}

int main()
{
	try {
		 Block<int> a(3, 0);							// 3 integers, all 0 
		 cout << a << endl;

		 Block<char> c(8, 'x');						// 8 chars, all x's
		 cout << c << endl;

		 Block<String> d(10, "abc");				// 10 Strings, all "abc"
		 cout << d << endl;
	}
	catch (const BlockError & e) {
		e.response();
		return 1;
	}
	return 0; 
}

/*********************************************************************

$ block1
0 0 0 
x x x x x x x x 
abc abc abc abc abc abc abc abc abc abc 

*/
