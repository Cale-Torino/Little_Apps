// blockr.C - template BlockR class (Generic Base and Derived)
#include <iostream.h>
#include "Block2.h"
#include "String.h"

class BlockRError {							// BlockR exception object
private:
	char buf[80];
public:
	BlockRError(const char *msg) { sprintf(buf, "BlockR: %s", msg); }
	BlockRError(int index, int maxindex) {			// BlockRError subscript error
		sprintf(buf, "BlockR: subscript %d out of bounds, max subscript = %d",
				index, maxindex-1);
	}
	void response() const { cerr << buf << endl; }
};

template <class TYPE>
class BlockR : private Block<TYPE> {
public:
	explicit BlockR(int size = 1) : Block<TYPE>(size) { }
	BlockR(int size, const TYPE & value) : Block<TYPE>(size, value) { }
	TYPE & operator[](int i) { 
		if (i < 0 || i >= length())
			throw BlockRError(i, length());
		return Block<TYPE>::operator[](i);
	}
	const TYPE & operator[](int i) const { 
		if (i < 0 || i >= length())
			throw BlockRError(i, length());
		return Block<TYPE>::operator[](i);
	}
	using Block<TYPE>::length;						// using declaration
};

template <class TYPE>
ostream & operator<<(ostream & os, BlockR<TYPE> & b) {
	for (int i = 0; i < b.length(); i++)
		os << b[i] << ' ';
	return os;
}

double Block<double>::ival = 0.0;
String Block<String>::ival = "";

template <class TYPE>
int Block<TYPE>::count = 0;					// template initialization
int Block<char>::count = 0;					// specialized initialization
int Block<int>::count = 0;						// specialized initialization

int main()
{
	try {
		BlockR<int> a;								// one integer, set to 0
		cout << a << endl;

		BlockR<double> b(10);					// 10 doubles, all 0
		cout << b << endl;

		BlockR<char> c(10, ' ');				// 10 chars, all blanks
		cout << c << endl;

		BlockR<String> d(10, "abc");			// 10 Strings, all "abc"
		cout << d << endl;
		cout << "length is " << d.length() << endl; 

		BlockR<String> *ps = new BlockR <String> (10);	// 10 Strings, all ""
		cout << *ps << endl;
		delete ps;

		BlockR<double> e(10, 1.1);				// 10 doubles, all 1.1 
		cout << e << endl;
		e[11] = 1.2;								// bogus

		BlockR<double> f(10, 1.1);				// 10 doubles, all 1.1 
		cout << f << endl;
		f[11] = 1.2;								// range check
	}
	catch (const BlockRError & e) {
		e.response();
		return 1;
	}
   return 0; 
}

/*********************************************************************

$ blockr
0 
0 0 0 0 0 0 0 0 0 0 
                    
abc abc abc abc abc abc abc abc abc abc 
length is 10
          
1.1 1.1 1.1 1.1 1.1 1.1 1.1 1.1 1.1 1.1 
BlockR: subscript 11 out of bounds, max subscript = 9

*/
