// itoh2.c - recursive integer to hex conversion, returns buffer
#include <iostream.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	unsigned int num;
	char *itoh(unsigned int);						// returns character pointer

	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " number" << endl;
		return 1;
	}
	num = atoi(argv[1]);
	cout << itoh(num) << endl;					// conversion routine
	return 0;
}

char *itoh(unsigned int num)
{
    unsigned int digit;
    static unsigned int offset;
    static const char *hex = "0123456789abcdef";
    static char str[sizeof(unsigned int) * 8 + 1];

    if ((digit = num / 16) != 0) 
        itoh(digit);								// recursive call
    else 
        offset = 0;

    str[offset++] = hex[num % 16];
    str[offset] = '\0';
    return str;
}

/*************************************************************************

$ itoh2 23456

*/
