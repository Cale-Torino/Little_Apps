// rotate.C - rotation routines
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

const int wordsize = sizeof(unsigned int) * 8;

#ifdef DRIVER
int main(int argc, const char *argv[])
{
	unsigned int num1, num2, nbits;
	unsigned int rol(unsigned int, unsigned int); 
	unsigned int ror(unsigned int, unsigned int);

	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " word(hex) nbits" << endl;
		return 1;
	}
	sscanf(argv[1], "%x", &num1);					// input in hex
	sscanf(argv[2], "%d", &nbits);				// input in decimal
	num2 = num1;										// save input
	
	cout << "rotate left " << nbits << " bits = " << hex << 
		rol(num1, nbits) << endl;
	
	cout << "rotate right " << nbits << " bits = " << hex << 
		ror(num2, nbits) << endl;
	return 0;
}
#endif

unsigned int rol(unsigned int word, unsigned int n)		// rotate left 
{
	if (n >= wordsize)								// check for shift overflow
		n %= wordsize;
	if (n > 0)
		return (word << n) | (word >> wordsize - n);
	return word;
}

unsigned int ror(unsigned int word, unsigned int n)		// rotate right
{
	if (n >= wordsize)								// check for shift overflow
		n %= wordsize;
	if (n > 0) 
		return (word >> n) | (word << wordsize - n);
	return word;
}

/*************************************************************************

$ rotate abcdef00 4
rotate left 4 bits = bcdef00a
rotate right 4 bits = abcdef0

*/
