// ptf3.c - pointers to template functions
#include <iostream.h>
#include "String.h"

template <class TYPE>
inline void add(TYPE & e, const TYPE & v) { e += v; }

template <class TYPE>
inline void sub(TYPE & e, const TYPE & v) { e -= v; }

void apply(int *a, int len, void (*pf)(int &, const int &),
				const int & nv) {
	for (int i = 0; i < len; i++)
		pf(a[i], nv); 
}

void apply(String *a, int len, void (*pf)(String &, const String &),
				const String & nv) {
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
	apply(s, 3, add, a); 				// apply add() to String array s
	print(s, 3);							// displays alphabet longbet bigbet 

	static String t[2] = { "hello", "over" };
	String b = "there";					// concatenation String
	apply(t, 2, sub, b); 				// apply sub() to String array t
	print(t, 2);							// displays hello there over there

	static int m[4] = { 12, 14, 16, 18 };
	apply(m, 4, add, 2);					// apply add() to integer array m
	print(m, 4);							// displays 14 16 18 20 

	static int n[3] = { 12, 15, 18 };
	apply(n, 3, sub, 3);					// apply sub() to integer array n
	print(n, 3);							// displays 9 12 15
	return 0;
}

/**********************************************************************

$ ptf3
alphabet longbet bigbet 
hello there over there 
14 16 18 20 
9 12 15 

NOTES:
1. We can't have apply(), add(), and sub() all be template functions
	because they won't instantiate properly.  In this situation, the
	the compiler doesn't know what type to use.

1. To instantiate properly, we need to specialize versions of apply()
	for the types we need.  That way, calls to non-template versions of
	apply() with template functions add() and sub() will instantiate
	correctly.

2. In this program, we provide two non-template versions of apply(),
	one for Strings and one for integers.

*/
