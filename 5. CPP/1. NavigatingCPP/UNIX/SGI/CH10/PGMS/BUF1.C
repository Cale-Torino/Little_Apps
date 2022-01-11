// buf1.C - Buffer objects
#include <iostream.h>
#include "Buffer.h"
#include "String.h"

int main() 
{
	try {
		 int i = 2;
		 String a[10], b[10];						// built-in String arrays
		 a[0] = "one";
		 a[1] = "two";
		 a[2] = "three";
		 for (i = 0; i < 3; i++)
		 	cout << a[i] << ' ';
		 cout << endl;
		 //String c[10] = a;							// illegal
		 //b = a;											// illegal

		 Buffer<String, 10> s, t;					// Buffer of 10 Strings
		 s[0] = "one";
		 s[1] = "two";
		 s[2] = "three";

		 Buffer<String, 10> u = s;				// Buffer copy initialization
		 for (i = 0; i < 3; i++)
		 	cout << u[i] << ' ';
		 cout << endl;

		 t = s;											// Buffer assignment
		 for (i = 0; i < 3; i++)
		 	cout << t[i] << ' ';
		 cout << endl;

		 cout << t[-1] << endl;						// range error
	}
	catch (const BufferError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/****************************************************************************

$ buf1
one two three 
one two three 
one two three 
Buffer: subscript -1 out of bounds, max subscript = 9

*/
