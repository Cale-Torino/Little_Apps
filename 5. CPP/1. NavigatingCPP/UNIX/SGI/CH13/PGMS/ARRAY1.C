// array1.C - Array class, exception hierarchy
#include <iostream.h>
#include <stdlib.h>
#include "Array.h"

int main(int argc, const char *argv[])
{
	if (argc != 3) {
		cerr << argv[0] << " length index" << endl;
		return 1;
	}
	int use_array(int, int);

	int len = atoi(argv[1]); 
	int index = atoi(argv[2]);
	return use_array(len, index);
}

int use_array(int len, int index)
{
	try {													// try block
		Array<int> a(len);							// Array of ints
		for (int i = 0; i < a.length(); i++)
			a[i] = i;									// fill with integers 

		cout << a[index] << endl;					// range check
	}
	catch (const ArrayError & err) {				// any ArrayError
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/*************************************************************************

$ array1 -10 5     
Array size error, bad size = -10

$ array1 10 15
Upper Bound Range Error, Bad Index = 15, Max Index = 9

$ array1 10 -5
Lower Bound Range Error, Bad Index = -5, Min Index = 0

$ array1 10 5
5

*/
