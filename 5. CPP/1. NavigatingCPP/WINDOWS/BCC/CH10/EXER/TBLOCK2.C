// tblock2.C - template Block class, specialized, default values
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
char Block<char>::ival = ' ';					// specialized initialization
int Block<int>::ival = 0;						// specialized initialization

int Block<char>::count = 0;					// specialized initialization
int Block<int>::count = 0;						// specialized initialization

int main()
{
	try {
		 Block<String> a(10, "abc");				// 10 Strings, all "abc"
		 Block<String> b = a;						// copy initialization
		 Block<String> c;								// "" String
		 cout << Block<String>::getcount() << " String objects" << endl;
		 c = b;											// assignment
		 cout << c << endl;

		 Block<char> d(10, 'x');					// 10 chars, all 'x'
		 Block<char> e = d;							// copy initialization
		 Block<char> f;								// ' ' char
		 cout << Block<char>::getcount() << " char objects" << endl;
		 f = e;											// assignment
		 cout << f << endl;

		 Block<int> r(10, 5);						// 10 integers, all 5
		 Block<int> s = r;							// copy initialization
		 Block<int> t;									// 0 integer
		 cout << Block<int>::getcount() << " integer objects" << endl;
		 t = s;											// assignment
		 cout << t << endl;
	}
	catch (const BlockError & e) {
		e.response();
		return 1;
	}
	return 0; 
}

/*********************************************************************
                                                            
$ tblock2
3 String objects
abc abc abc abc abc abc abc abc abc abc 
3 char objects
x x x x x x x x x x 
3 integer objects
5 5 5 5 5 5 5 5 5 5 

*/
