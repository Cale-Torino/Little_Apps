// itoh1.C - non-recursive integer to hex conversion 
#include <iostream.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	unsigned int num;
	void itoh(unsigned int);

	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " number" << endl;
		return 1;
	}
	num = atoi(argv[1]);
	itoh(num);											// conversion routine
	cout << endl;
	return 0;
}

void itoh(unsigned int n)
{
	const int max = 10;
	unsigned int d, i = 0;
	char buf[max];

	for (; n != 0; n /= 16) {
  		d = n % 16;										// next digit
  		buf[i++] = (d <= 9) ? d + '0' : d + 'a' - 10;
	}
	while (i)											// output hex chars backwards
  		cout << buf[--i];
}


/*************************************************************************

$ itoh1 23456
5ba0

The non-recursive solution has a for loop that stores each character 
backwards in the buf character array.  
This requires a second loop (while) to output each hex char in
reverse.  
This is slow and inefficient.

*/
