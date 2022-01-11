// array2.C - Array class, exception hierarchy, discrimination
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
	catch (const SizeError & err) {
		err.response();								// virtual call
		cout << "Input new length: ";
		cin >> len;
		return use_array(len, index);				// retry
	}
	catch (const ArrayError & err) {				// all others
		err.response();								// virtual call
		return 1;
	}
	return 0;
}

/*************************************************************************

$ array2 -10 5     
Array size error, bad size = -10
Input new length: 10
5

*/
