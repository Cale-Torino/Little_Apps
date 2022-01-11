// rnum3.C - Roman objects, integer to Roman conversions
#include <iostream.h>
#include "Roman3.h"

int main()
{
	try {
		 Roman r1 = 5719;
		 Roman r2 = "WMMMCCCXXXIX";
		 Roman r3 = r2;
		 cout << r1.getnum() << " is " << r1.getroman() << endl;
		 cout << r2.getnum() << " is " << r2.getroman() << endl;
		 cout << r3.getnum() << " is " << r3.getroman() << endl;
		 Roman r4 = "CCXXXXV";			// illegal Roman string
	}
	catch (const RomanError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**************************************************************************

$ rnum3
5719 is WDCCXIX
8339 is WMMMCCCXXXIX
8339 is WMMMCCCXXXIX
Roman: CCXXXXV is an illegal Roman string

*/
