// ptf3.c - pointers to template functions
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline void add(TYPE & e, const TYPE & v) { e += v; }

template <class TYPE>
inline void sub(TYPE & e, const TYPE & v) { e -= v; }

template <class TYPE>
void apply(TYPE *a,int len,void (*pf)(TYPE &,const TYPE &),const TYPE & nv) {
	for (int i = 0; i < len; i++)
		pf(a[i], nv); 
}

template <class TYPE>
void print(const TYPE *a, int len) {
	for (int i = 0; i < len; i++)
		cout << a[i] << ' ';
	cout << endl;
}

int main()
{
	static String s[3] = { "alpha", "long", "big" };
	String a = "bet";						// concatenation String
	//apply(s, 3, add, a); 				// apply add() to String array s
	print(s, 3);

	static int m[4] = { 12, 14, 16, 18 };
	//apply(m, 4, sub, 2);					// apply sub() to integer array m
	print(m, 4);
	return 0;
}

/**********************************************************************

$ ptf3 
alpha long big 
12 14 16 18 

*/
