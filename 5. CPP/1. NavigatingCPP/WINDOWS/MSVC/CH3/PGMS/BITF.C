// bitf.c - bitfields
#include <iostream.h>
#include <iomanip.h>

int main()
{
	struct dbyte {
		unsigned int flag : 1;				// one bit
		unsigned int mode : 2;				// two bits
		unsigned int 	  	: 1;				// unused
		unsigned int type : 4;				// four bits
	};

	dbyte v = { 0 };						// create word with bitfields
	v.flag = 1;								// 0000 0000 0000 0001
	v.mode = 3;								// 0000 0000 0000 0111
	v.type = 9;								// 0000 0000 1001 0111

	int n = *reinterpret_cast<int *>(&v);	
	cout << hex << n << endl;			// displays 97 or e900 (hex)
	return 0;
}

/****************************************************************

$ bitf
97

*/
