// memset.c - set array of objects to value
#include <iostream.h>
#include <iomanip.h>
#include <memory.h>
#include "String.h"
#include "Complex.h"

template <class TYPE>
void fill(TYPE *a, const TYPE & val, int length) {
	cout << "template" << endl;
	for (int i = 0; i < length; i++)
		a[i] = val;
}

inline void fill(char *a, char val, int length) {
	cout << "specialize" << endl;
	memset(a, val, length);
}

template <class TYPE>
void dump(TYPE *a, int length) {
	for (int i = 0; i < length; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

int main()
{
	char a[10], ch = 'x';
	int b[10], n = 5;
	String c[10], s("abc");
	Complex d[10], v(1.1, 3.5);

	fill(a, ch, 10);								// fill with char 'x'
	dump(a, 10);
	fill(b, n, 10);								// fill with integer 5
	dump(b, 10);
	fill(c, s, 10);								// fill with String "abc"
	dump(c, 10);
	fill(d, v, 10);								// fill with Complex (1.1, 3.5)
	dump(d, 10);
	return 0;
}

/*******************************************************************

$ memset
specialize
   x   x   x   x   x   x   x   x   x   x
template
   5   5   5   5   5   5   5   5   5   5
template
 abc abc abc abc abc abc abc abc abc abc
template
   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)   (1.1, 3.5)

*/
