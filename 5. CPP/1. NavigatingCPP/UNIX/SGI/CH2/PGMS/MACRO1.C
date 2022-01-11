// macro1.c - MIN and MAX macros
#include <iostream.h>

#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))

int main()
{
	int m = 12, n = 34;
	static int s[100] = { 1, 2, 3 };
	float a = 4.5, b= 6.7;
	int i = 2;

	cout << MAX(m+n, s[i]) << endl;					// maximum of integers
	cout << MIN(a, b) * 100 << endl;					// maximum of integers
	return 0;
}

/**********************************************************************

$ macro1
46
450

*/
