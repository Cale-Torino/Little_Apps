// ex6.C - Macros
#include <iostream.h>

#define SET(W, B) ((W) |= (1 << (B)))
#define RESET(W, B) ((W) &= ~(1 << (B)))
#define TEST(W, B) ((W) & (1 << (B)))

int main()
{
	int a = 4;										// integer a
	long b = 15;									// long b

	SET(a, 1);										// turn on bit 1 in integer a
	cout << a << endl;							// displays 6

	RESET(b, 3);									// turn off bit 3 in character b
	cout << b << endl;							// displays 7

	if (TEST(a, 1))								// see if bit 1 is on in integer a
		cout << "bit 1 is on in " << a << endl;
	return 0;
}

/**************************************************************************

$ ex6
6
7
bit 1 is on in 6

The SET macro turns on a bit by generating a mask with (1 << (B)).
This mask left shifts constant 1 by the number of bits requested (B).
The macro turns on the bit by performing a bitwise OR 
with assignment (|=) using word (W) and the mask.  

The RESET macro turns off a bit by generating a mask with ~(1 << (B)).
This mask left shifts constant 1 by the number of bits requested (B)
and complements all the bits in the mask.
The macro turns off the bit by performing a bitwise AND 
with assignment (&=) using word (W) and the mask.  

The TEST macro tests a bit by generating a mask with (1 << (B)).
This mask left shifts constant 1 by the number of bits requested (B).
The macro tests the bit by performing a bitwise AND using word (W) 
and the mask.
The result is either true (1) or false (0).

These macros are fast inline bit manipulators. 
There is no overhead, since the operators evaluate their operands 
at compile time.

The macros are machine independent because the compiler generates masks
in each macro.  Note that in all masks, the compiler left shifts a
constant 1, which will always be the word size of the machine.

*/
