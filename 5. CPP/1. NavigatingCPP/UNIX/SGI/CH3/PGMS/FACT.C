// fact.c - recursive inline factorial
#include <iostream.h>
#include <stdlib.h>

inline unsigned int fact(unsigned int n) {
	return (n <= 1) ? 1 : n * fact(n-1);
}

int main(int argc, const char *argv[])
{
	if (argc == 1) {
		cerr << "Usage: " << argv[0] << " number" << endl;
		return 1;
	}
	int num = atoi(argv[1]);
	cout << fact(num) << endl;
	return 0;
}

/*******************************************************************

$ fact 5
120

*/
