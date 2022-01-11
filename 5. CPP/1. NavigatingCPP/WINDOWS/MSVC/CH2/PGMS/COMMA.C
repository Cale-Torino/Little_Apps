// comma.c - SWAP macro
#include <iostream.h>

#define SWAP(A, B) ((A) ^= (B), (B) ^=(A), (A) ^= (B)) 

int main()
{
	int m = 12, n = 34;

	SWAP(m, n);											// swap integers
	cout << m << ' ' << n << endl;				// displays 34 12
	return 0;
}

/**********************************************************************

$ comma
34 12

*/
