// macro2.c - SWAP macro
#include <iostream.h>

#define SWAP(A, B) { \
	int TMP; \
	(TMP) = (A); \
	(A) = (B); \
	(B) = (TMP); \
}

int main()
{
	int m = 12, n = 34;
	float a = 4.5, b= 6.7;

	SWAP(m, n);											// swap integers
	SWAP(a, b);											// swap floats
	cout << m << ' ' << n << endl;				// displays 34 12 (correct)
	cout << a << ' ' << b << endl;				// displays 6.7 4 (wrong)
	return 0;
}

/**********************************************************************

$ macro2
34 12
6.7 4

*/
