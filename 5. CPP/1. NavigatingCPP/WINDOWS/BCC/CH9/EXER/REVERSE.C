// reverse.c - reverse array elements in place
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline void swap(TYPE & a, TYPE & b) {
	TYPE tmp = a;
	a = b;
	b = tmp;
}

template <class TYPE>
void reverse(TYPE *array, int len) {
   for (int i = 0; i < len/2; i++)
	  swap(array[i], array[len-i-1]);
}

template <class TYPE>
void display(const TYPE *a, int len) {
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	static int a[5] = { 12, 47, -33, 101, 56 };
	reverse(a, 5);
	display(a, 5);

	static String b[4] = { "one", "two", "three", "four" };
	reverse(b, 4);
	display(b, 4);
	return 0;
}

/**********************************************************************

$ reverse
56 101 -33 47 12 
four three two one  

*/
