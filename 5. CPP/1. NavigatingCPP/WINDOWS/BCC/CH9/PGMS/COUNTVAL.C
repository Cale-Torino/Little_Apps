// countval.c - countval() template function
#include <iostream.h>
#include "String.h"

template <class TYPE>
int countval(const TYPE *array, int size, TYPE val) {
	int count = 0;
	for (int i = 0; i < size; i++)
		if (array[i] == val)
			count++;
	return count;
}

int main()
{
	static double b[6] = { 3, -12.7, 3, 13.9, 44.8, 68.22 };
	//cout << countval(b, 6, 3) << endl;					// illegal - no match
	cout << countval(b, 6, 3.) << endl;						// displays 2

	static String c[4] = { "one", "two", "three", "four" }; 
	//cout << countval(c, 4, "three") << endl;			// illegal - no match
	cout << countval(c, 4, String("three")) << endl;	// displays 1
	return 0;
}

/**********************************************************************

$ countval 
2
1

*/
