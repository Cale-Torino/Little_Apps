// scmp.C - string comparisons for three or more character strings
#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int main()
{
	bool scmp(int, ...);						// variable arg list prototype
	char *s1 = "one";
	char *s2 = "two";
	char *s3 = "three";
	char *s4 = "four";

	cout << (scmp(3, s1, s2, s3) ? "same" : "different") 
			<< " strings" << endl;
	cout << (scmp(4, s1, s2, s3, s4) ? "same" : "different") 
			<< " strings" << endl;
	cout << (scmp(4, s1, s1, s1, s1) ? "same" : "different") 
			<< " strings" << endl;
	return 0;
}

bool scmp(int num, ...) {
	va_list args;									// argument list
	va_start(args, num);							// init argument list, get number
	const char *s, *t;
	bool rval = true;								// return value

	s = va_arg(args, const char *);			// get first string

	while(--num) {
		t = va_arg(args, const char *);		// get next string
		if (strcmp(s, t)) {						// are they the same?
			rval = false;								// strings are different
			break;
		}
	}
	va_end(args);									// cleanup argument list
	return rval;									// return result
}

/*******************************************************************

$ scmp
different strings
different strings
same strings

*/
