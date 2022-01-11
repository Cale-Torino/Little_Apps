// ptf2.c - pointers to template functions
#include <iostream.h>
#include "String.h"

inline void join(String & e, const String & v) { e += v; }
inline void joinb(String & e, const String & v) { e -= v; }

inline void multiply(int & e, const int & v) { e *= v; }
inline void divide(int & e, const int & v) { e /= v; }

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
	apply(s, 3, join, a); 				// apply join() to String array s
	print(s, 3);							// displays alphabet longbet bigbet 

	static String t[2] = { "hello", "over" };
	String b = "there";					// concatenation String
	apply(t, 2, joinb, b); 				// apply joinb() to String array t
	print(t, 2);							// displays hello there over there

	static int m[4] = { 12, 14, 16, 18 };
	apply(m, 4, multiply, 2);			// apply multiply() to integer array m
	print(m, 4);							// displays 24 28 32 36 

	static int n[3] = { 12, 15, 18 };
	apply(n, 3, divide, 3);				// apply divide() to integer array n
	print(n, 3);							// displays 4 5 6 
	return 0;
}

/**********************************************************************

$ ptf2 
alphabet longbet bigbet 
hello there over there 
24 28 32 36 
4 5 6 

*/
