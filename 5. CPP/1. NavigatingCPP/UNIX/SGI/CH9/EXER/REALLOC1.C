// realloc1.C - reallocate free store memory
#include <iostream.h>
#include "String.h"
#include "Rnew1.h"

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
	}
	catch (char *msg) {
		cerr << msg << endl;
		return 1;
	}
	return 0;
}

/**********************************************************************

$ realloc1
one two three four five 
1 2 3 4 5 

NOTES:
1. The template rnew() function calls operator new[] with a TYPE 
	before the for loop copies each element.
	This call to operator new[] invokes a default constructor for TYPE for
	each element. Inside the for loop, the function uses assignments to
	copy each element, possibly invoking overloaded assignments for TYPE.

2. This arrangement is inefficient, because calls to the default
	constructor are not necessary.

3. Another problem with this design is rnew()'s second argument (old length).
	Applications must "remember" and manage this important variable;
	otherwise, rnew() can cause problems when it reallocates memory.

*/
