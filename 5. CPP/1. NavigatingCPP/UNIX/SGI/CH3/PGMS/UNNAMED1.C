// unnamed1.C - unnamed namespaces
#include <iostream.h>

namespace {										// unnamed namespace
	const int Max = 20;
	int buffer[Max];
	int counter;
}

void sub1() {
	counter = 0;								// counter in unnamed namespace
	for (int i = 0; i < Max; i++)			// Max in unnamed namespace
		buffer[i] = i*2;						// buffer in unnamed namespace
	for (int j = 0; j < Max; j++)
		cout << buffer[j] << ' ';
	cout << endl;
	cout << counter << endl;
}

int main()
{
	sub1();
	return 0;
}

/************************************************************************

$ unnamed1
0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 
0

*/
