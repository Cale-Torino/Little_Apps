// a2d.c - two-dimensional arrays as function arguments
#include <iostream.h>

void f(int (*)[10]);								// 2D function prototype
void f(int [][10]);								// 2D equivalent prototype

int main()
{
	static int a[5][10] = { 1, 2 };			// 2D array of 10 integers
	f(a);												// call function with 2D array
	return 0;
}

void f(int (*p)[10]) {							// 2D function definition
	int i = 0, j = 1;
	cout << p[i][j] << endl;					// 2D array subscript
}

/*******************************************************************

$ a2d
2

*/
