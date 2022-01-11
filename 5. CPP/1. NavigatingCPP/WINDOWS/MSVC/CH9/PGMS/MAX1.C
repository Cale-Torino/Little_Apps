// max1.c - max() integer function
#include <iostream.h>

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main()
{
	int m = 43, n = 56;
	cout << max(m, n) << endl;					// displays 56 (CORRECT)

	double x = 4.3, y = 5.6;
	cout << max(x, y) << endl;					// displays 5 (WRONG)
	return 0;
}

/**********************************************************************

$ max1 
56
5

*/
