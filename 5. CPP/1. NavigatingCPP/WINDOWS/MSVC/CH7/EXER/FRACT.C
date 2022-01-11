// fract.C - Fraction class
#include <iostream.h>
#include "Fraction.h"

int main()
{
	try {
		 Fraction n(3, 4);
		 Fraction m;
		 cin >> m;
		 cout << n << ' ' << m << endl;
		 cout << m + n << ' ' << m * n << endl;
	}
	catch (const FractionError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ fract 
Input numerator: 7
Input denominator: 8
0.75 0.875
1.625 0.65625

$ fract 
Input numerator: 7
Input denominator: 0
Fraction: denominator can't be zero

NOTES:
1. Fraction does NOT require the full boilerplate because there are no
	pointer state variables and the Fraction constructor does not allocate
	resources.

2. Addition with operator+() and multiplication with operator*() should be
	non-member functions because of symmetry with operaands requiring
	implicit conversions.
	
3. Note that operator>> for istream does NOT have to be a friend in this 
	design because default Fraction assignments update the input Fraction 
	object from a local object we create with a Fraction constructor.  
	This technique is slower but more encapsulated than a friend 
	implementation, which inputs directly into the numerator and 
	denominator of Fraction objects.

*/
