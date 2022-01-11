// itoh2.C - integer to hex conversion using anonymous unions for shorts
#include <iostream.h>
#include <stdlib.h>

#ifdef INTEL
const int byte = 0;						// INTEL based
#else
const int byte = 1;
#endif

int main(int argc, const char *argv[])
{
	unsigned short num;
	void itoh(unsigned short);

	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " number" << endl;
		return 1;
	}
	num = atoi(argv[1]);
	itoh(num);								// conversion routine
	cout << endl;
	return 0;
}
void itoh(unsigned short n)
{
	union {										// anonymous union
		unsigned short num;
		unsigned char s[sizeof(short)];
	};
	const char *hex = "0123456789abcdef";
	num = n;									// store number as a short

	cout << hex[s[byte] >> 4];						// first byte - high nibble
	cout << hex[s[byte] & 15];						// first byte - low nibble				

	cout << hex[s[!byte] >> 4];					// second byte - high nibble
	cout << hex[s[!byte] & 15];					// second byte - low nibble
}

/*******************************************************************

$ itoh2 23456
5ba0

*/
