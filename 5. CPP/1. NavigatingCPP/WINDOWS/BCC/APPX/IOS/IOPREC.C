// ioprec.c - i/o precision
#include <iostream.h>
#include <iomanip.h>
#include <stdio.h>

int main()
{
	float x = 6.12345678;
	printf("%6.2f\n", x);				// call to C printf()

	int oldp = cout.precision(3);		// save current precision
	cout << setw(6) << x << endl;
	cout.precision(oldp);				// restore old precision
	cout << x << endl;
	return 0;
}

/*************************************************************

$ ioprec
  6.12
  6.12
6.12346

*/
