// a3d.c - three-dimensional arrays as function arguments
#include <iostream.h>

void f(int (*)[10][20]);						// 3D function prototype
void f(int [][10][20]);							// 3D equivalent prototype

int main()
{
	static int a[5][10][20] = { 1, 2 };		// 3D array of 10 integers
	f(a);												// call function with 3D array
	return 0;
}

void f(int (*p)[10][20]) {						// 3D function definition
	int i = 0, j = 0, k = 1 ;
	cout << p[i][j][k] << endl;				// 3D array subscript
}

/*******************************************************************

$ a3d
2

*/
