// a1d.c - one-dimensional arrays as function arguments
#include <iostream.h>

void f(int *);										// 1D function prototype
void f(int []);									// 1D equivalent prototype

int main()
{
	static int a[10] = { 1, 2 };				// 1D array of 10 integers
	f(a);												// call function with 1D array
	return 0;
}

void f(int *p) {									// 1D function definition
	int i = 1;
	cout << p[i] << endl;						// 1D array subscript
}

/*******************************************************************

$ a1d
2

*/
