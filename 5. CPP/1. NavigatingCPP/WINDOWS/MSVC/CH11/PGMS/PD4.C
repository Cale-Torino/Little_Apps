// pd4.c - private derivation, incorrect for BArray
#include <iostream.h>
#include "Barray.h"

template <class TYPE>
void debug(const Array<TYPE> &) { cout << "Array<TYPE>" << endl; }
//void debug(const Array<int> &) { cout << "Array<int>" << endl; }

template <class TYPE>
void debug(const BArray<TYPE> &) { cout << "BArray<TYPE>" << endl; }
//void debug(const BArray<int> &) { cout << "BArray<int>" << endl; }

int main()
{
	try {
		 BArray<int> b(10, 15);					// BArray of 6 integers
		 debug(b);									// which debug()?
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}
