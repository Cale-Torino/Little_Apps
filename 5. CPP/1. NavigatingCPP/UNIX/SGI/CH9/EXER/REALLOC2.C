// realloc2.C - reallocate free store memory, specialized
#include <iostream.h>
#include "String.h"
#include "Rnew2.h"

int main()
{
	try {
		String *ps = new String[3];							// Array of Strings
		ps[0] = "one";  ps[1] = "two";  ps[2] = "three";
		int i;

		ps = rnew(ps, 3, 5);										// increase by 2
		ps[3] = "four";  ps[4] = "five";

		for (i = 0; i < 5; i++)
			cout << ps[i] << ' ';
		delete [] ps;												// free space
		cout << endl;

		int *pi = new int[3];									// Array of ints
		pi[0] = 1;  pi[1] = 2;  pi[2] = 3;

		pi = rnew(pi, 3, 5);										// increase by 2
		pi[3] = 4;  pi[4] = 5;

		for (i = 0; i < 5; i++)
			cout << pi[i] << ' ';
		cout << endl;
		delete [] pi;												// free space

		double *pd = new double[3];							// Array of doubles
		pd[0] = 1.1;  pd[1] = 2.1;  pd[2] = 3.1;

		pd = rnew(pd, 3, 5);										// increase by 2
		pd[3] = 4.1;  pd[4] = 5.1;

		for (i = 0; i < 5; i++)
			cout << pd[i] << ' ';
		cout << endl;
		delete [] pd;												// free space
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ realloc2
one two three four five 
1 2 3 4 5 
1.1 2.1 3.1 4.1 5.1 

NOTES:
1. The specialized versions of rnew() perform better than the template
	version because the compiler does not call any default constructors
	for integers and doubles.

2. Also, memcpy() is faster than a for loop to move integers and doubles.

*/
