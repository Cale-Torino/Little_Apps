// block2.C - template Block class, specialized, default values
#include <iostream.h>
#include <memory.h>
#include "Block2.h"
#include "String.h"

template <class TYPE>
ostream & operator<<(ostream & os, const Block<TYPE> & b) {
	for (int i = 0; i < b.length(); i++)
		os << b[i] << ' ';
	return os;
}

template <class TYPE>
int Block<TYPE>::count = 0;					// template initialization

String Block<String>::ival = "";				// specialized initialization
int Block<char>::count = 0;					// specialized initialization
int Block<int>::count = 0;						// specialized initialization

int main()
{
	try {
		 Block<int> a(2);								// two integers, set to 0
		 cout << a << endl;

		 Block<int> b(3, -1);						// 3 integers, all -1 
		 cout << b << endl;

		 Block<char> c(8, 'x');						// 8 chars, all x's
		 cout << c << endl;

		 Block<String> d(10, "abc");				// 10 Strings, all "abc"
		 cout << d << endl;

		 Block<String> e(10);						// 10 Strings, all ""
		 cout << e << endl;

		 Block<String>::initial_value("...");
		 Block<String> f(10);						// 10 Strings, all "..."
		 cout << f << endl;

		 cout << Block<String>::getcount() << " Strings" << endl;
		 cout << Block<char>::getcount() << " chars" << endl;
		 cout << Block<int>::getcount() << " ints" << endl;
	}
	catch (const BlockError & e) {
		e.response();
		return 1;
	}
	return 0; 
}

/*********************************************************************
                                                            
$ block2
0 0 
-1 -1 -1 
x x x x x x x x 
abc abc abc abc abc abc abc abc abc abc 
          
... ... ... ... ... ... ... ... ... ... 
3 Strings
1 chars
2 ints

*/
