// ts1.c - type safe i/o
#include <iostream.h>
#include <stdio.h>

int main()
{
	char name[80] = "abc";					// 80 byte character array
	int digit = 12;							// integer
	printf("%s %d\n", digit, name);		// oops, wrong order

	cout << digit << ' ' << name << endl;		// displays 12 abc
	return 0;
}

/************************************************************************

$ ts1
CK -92							(garbage on our machine)
12 abc

*/
