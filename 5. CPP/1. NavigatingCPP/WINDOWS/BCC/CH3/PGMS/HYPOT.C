// hypot.c - exceptions
#include <iostream.h>
#include <math.h>

float hypot(float a, float b) throw(char *) {
	if (a == 0 || b == 0)
		throw "hypot(): sides must be nonzero";
	if (a < 0 || b < 0)
		throw "hypot(): sides must be positive values";
	return sqrt(a*a + b*b);
}

int main()
{
	try {
		float f, g;
		cout << "Input sides of right triangle: ";
		cin >> f >> g;
		cout << hypot(f, g) << endl;
	 }
	 catch (char *msg) {							// catch handler
	 	cerr << msg << endl;
	 	return 1;
	 }
	 return 0;
}

/*******************************************************************

$ hypot
Input sides of right triangle: 3 4
5

Input sides of right triangle: 0 4
hypot(): sides must be nonzero

Input sides of right triangle: -2 -6
hypot(): sides must be positive values

*/
