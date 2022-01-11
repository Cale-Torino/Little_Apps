// mt1.c - template Range numbers, member templates
#include <iostream.h>
#include "Range.h"

void bigfunction(const Range<double> & r1 ) {
	cout << "value = " << static_cast<double>(r1) << " min = "
			<< r1.min() << " max = " << r1.max() << endl;
}

int main()
{
	try {
		 Range<int> nineties(1995, 1990, 1999);
		 nineties = 1996;
		 cout << nineties << endl;

		 Range<float> value(1.1, -10.5, 10.5);
		 cout << value << endl;

		 Range<double> vision(.2, -.5, .5);
		 cout << vision << endl;

		 bigfunction(nineties);				// pass Range<int>
		 bigfunction(value);					// pass Range<float>
		 bigfunction(vision);					// pass Range<double>
		 value = 100;							// out of range, throws exception
	}
	catch (const RangeError<int> & e) {
		e.response();
		return 1;
	}
	catch (const RangeError<float> & e) {
		e.response();
		return 1;
	}
	catch (const RangeError<double> & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*******************************************************************************

$ mt1 
(1996, 1990, 1999)
(1.1, -10.5, 10.5)
(0.2, -0.5, 0.5)
value = 1996 min = 1990 max = 1999
value = 1.1 min = -10.5 max = 10.5
value = 0.2 min = -0.5 max = 0.5
Range: out of range (value = 100, min = -10.5, max = 10.5)

*/
