// cast6.c - traditional and functional casts
#include <iostream.h>

int main()
{
	float v = 10.5; int n = 97;
	cout << (int)v << endl;						// evaluates to 10 - traditional cast
	cout << (char)n << endl;					// evaluates to 'a' - traditional cast
	cout << char(n+4) << endl;					// evaluates to 'e' - functional cast

	unsigned char *pb1, *pb2;
	pb1 = (unsigned char *)0x800000;			// legal - traditional cast
	cout << pb1 << endl;
	//pb2 = unsigned char *(0x800000);			// illegal - functional cast
	pb2 = (unsigned char *)0x800000;			// legal - traditional cast

	typedef unsigned char * Pbyte;			// Pointer to memory byte
	Pbyte pb3 = Pbyte(0x800000);				// legal - functional cast
	cout << pb2 << endl;
	cout << pb3 << endl;
	return 0;
}

/**********************************************************************

$ cast6
10
a
e
0x800000
0x800000
0x800000

*/
