// fract.C - fraction class
#include <iostream.h>
#include "Fraction.h"

int main()
{
	try {
		Fraction n(12, 25);							// numerator=12, denominator=25
		cout << n << endl;

		Fraction m;
		cin >> m;										// input numerator, denominator
		cout << m << endl;

		Fraction w(10, 0);							// zero denominator
		cout << w << endl;
	}
	catch (const FractionError & err) {
		err.response();
		return 1;
	}
	return 0;
}

/****************************************************************

$ fract
0.48
Input numerator: 8
Input denominator: 4
2
Zero denominator for numerator 10

$ fract
0.48
Input numerator: 8
Input denominator: 0
Zero denominator for numerator 8

*/
