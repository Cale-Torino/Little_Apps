// min1.c - overloaded min functions
#include <iostream.h>

int min(int, int);							// minimum, two integers
float min(float, float);					// minimum, two floats
int min(const int *, int);					// minimum, integer array with size

int main()
{
	int m = 43, n = 56;
	cout << min(m, n) << endl;				// minimum of integers

	float v = 6.5, w = 8.9;
	cout << min(v, w) << endl;				// minimum of floats

	static int buf[8] = { 103, 33, 12, 56, 44, 29, 64, 202 };
	cout << min(buf, 8) << endl;			// minimum of an array of integers
	return 0;
}

int min(int a, int b) {								// minimum of two integers
	return a < b ? a : b;
}

float min(float a, float b) {						// minimum of two floats
	return a < b ? a : b;
}

int min(const int *p, int sz) {					// minimum of an integer array
	int minv = p[0];
	for (int i = 1; i < sz; i++)
		if (p[i] < minv)
			minv = p[i];
	return minv;	
}

/********************************************************************

$ min1
43
6.5
12

*/
