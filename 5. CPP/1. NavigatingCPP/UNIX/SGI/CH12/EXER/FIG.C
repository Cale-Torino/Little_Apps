// fig.C - Circles and Squares with Figure base class
#include <iostream.h>
#include "Figure.h"

int main()
{
	Circle c1(4);										// define Circle
	Square s1(8);										// define Square

	Circle c2(6);										// define Circle
	Square s2(12);										// define Square

	c1 += c2;											// make Circle c1 bigger
	c1 += s2;											// error

	s1 += s2;											// make Square s1 bigger
	s1 += c2;											// error

	cout << "c1 = " << c1 << endl;
	cout << "s1 = " << s1 << endl;
	return 0;
}

/**************************************************************************

$ fig
Circle: right operand should be a Circle
Square: right operand should be a Square
c1 = 314.159 for a Circle
s1 = 400 for a Square

*/
