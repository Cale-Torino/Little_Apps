// ex7.C - Assertions
#include <iostream.h>
#include <assert.h>

int main()
{
	const int max = 10;
	char c;
	int digit, index;
	int buffer[max];

	cout << "Input a digit and an index: ";
	cin >> c >> index;

	assert(c >= '0' && c <= '9'); 
	digit = c - '0';

	assert(index >= 0 && index < max);
	buffer[index] = digit;
	return 0;
}

/************************************************************************

$ ex7
Input a digit and an index: w 5
Assertion failed: c >= '0' && c <= '9', file ex7.c, line 15
Abort (core dump)

$ ex7
Input a digit and an index: 5 12
Assertion failed: index >= 0 && index < max, file ex7.c, line 18
Abort (core dump)

*/
