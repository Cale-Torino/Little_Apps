// rint1.c - Rint class, exception hierarchy, discrimination
#include <iostream.h>
#include <stdlib.h>
#include "Rint.h"

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cerr << argv[0] << " min max" << endl;
		return 1;
	}
	int use_range(int, int);

	int min = atoi(argv[1]); 
	int max = atoi(argv[2]);
	return use_range(min, max);
}

int use_range(int min, int max)
{
	try {													// try block
		Rint g(min, min, max);						// check initialization
 		cout << "Input an integer between " 
				<< min << " and " << max << endl;
 		cin >> g;										// istream input
 		cout << g << endl;							// ostream output
	}
	catch (const InitializerError & err) {
		err.response();								// virtual call
		cout << "Input new minimum: ";
		cin >> min;
		cout << "Input new maximum: ";
		cin >> max;
		return use_range(min, max);				// retry
	}
	catch (const RintError & err) {				// all others
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/*****************************************************************

$ rint1 10 1
Range Int initializer error:
min value = 10, max value = 1
Input new minimum: 1
Input new maximum: 10
Input an integer between 1 and 10
5
(5, 1, 10)

*/
