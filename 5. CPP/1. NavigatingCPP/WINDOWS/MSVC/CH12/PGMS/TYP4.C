// typ4.c - typepid(), polymorphic types
#include <iostream.h>
#include <typeinfo.h>
#include "Array.h"
#include "String.h"

template <class TYPE>
void fill(Array<TYPE> & a, int len, const TYPE *val) {
	cout << "filling Array<" << typeid(a[0]).name() << '>' << endl;
	int idx = 0;
	for (int i = 0; i < len; i++)
		a[i] = val[idx++];
}

int main()
{
	static int iv1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Array<int> a(10);
	fill(a, 10, iv1);
	cout << a << endl;

	Array<double> b(10);
	static double iv2[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	fill(b, 10, iv2);
	cout << b << endl;

	Array<String> c(5);
	static String iv3[] = { "one", "two", "three", "four", "five" };
	fill(c, 5, iv3);
	cout << c << endl;
	return 0;
}

/*************************************************************************

$ typ4 
filling Array<int>
1 2 3 4 5 6 7 8 9 10 
filling Array<double>
10 9 8 7 6 5 4 3 2 1 
filling Array<class String>
one two three four five 

*/
