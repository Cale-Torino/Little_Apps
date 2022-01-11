// min2.c - overloaded min functions
#include <iostream.h>

int min(int, int);									// minimum of two integers
double min(int, double);							// minimum of integer, double
double min(double, int);							// minimum of double, integer
double min(double, double);						// minimum of two doubles

int main()
{
	int m = 43, n = 56;
	double v = 6.5, w = 8.9;

	cout << min(m, n) << endl;						// minimum of integers
	cout << min(v, w) << endl;						// minimum of doubles
	cout << min(m, w) << endl;						// minimum of mixed types
	cout << min(v, n) << endl;						// minimum of mixed types
	return 0;
}

int min(int a, int b) {								// minimum of two integers
	return a < b ? a : b;
}

double min(int a, double b) {						// minimum of integer, double
	return a < b ? a : b;
}

double min(double a, int b) {						// minimum of double, integer
	return a < b ? a : b;
}

double min(double a, double b) {					// minimum of two doubles
	return a < b ? a : b;
}

/********************************************************************

$ min2
43
6.5
8.9
6.5

NOTES:

1. With only (int, int) and (double, double) prototypes, the compiler reports
	ambiguities when min(int, double) and min(double, int) is called. This is
	because the compiler can either promote an integer to a double or cast a 
	double to int.

2. Four prototypes handle the situation nicely, since exact matches occur on
	all possibilities and applications do not have to cast arguments or change
	data types.

*/
