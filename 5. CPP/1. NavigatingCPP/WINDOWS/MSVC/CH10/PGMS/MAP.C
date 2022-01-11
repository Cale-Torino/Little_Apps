// map.c - associative arrays
#include <iostream.h>
#include "Assoc.h"
#include "String.h"
#include "Complex.h"
#include "Polar.h"

int main()
{
	try {
		Assoc<String, String> spanish(1000);				// 1000 Spanish words
		spanish["beach"] = "playa";							// map English to Spanish
		spanish["beer"] = "cerveza";							// lvalue
		cout << spanish["beer"] << endl;						// rvalue - Ok

		Complex c1(1.1, 2.3);									// Complex number
		Polar p1 = c1;												// Polar number
		Assoc<Complex, Polar> point(100);					// 100 points
		point[c1] = p1;											// map Polar to Complex
		cout << "Complex: " << c1 << endl;
		cout << "Polar: " << point[c1] << endl;

		cout << spanish["burger"] << endl;					// lvalue - error,no entry
	}
	catch (const AssocError<String, String> & e) {		// catch handler
		e.response();												// display error message
		return 1;
	}
	catch (const AssocError<Complex, Polar> & e) {		// catch handler
		e.response();												// display error message
		return 1;
	}
	return 0;
}

/**********************************************************************

$ map 
cerveza
Complex: (1.1, 2.3)
Polar: radius = 2.54951 cos(theta) = 0.431455 sin(theta) = 0.902134
Assoc: could not find "burger"

*/
