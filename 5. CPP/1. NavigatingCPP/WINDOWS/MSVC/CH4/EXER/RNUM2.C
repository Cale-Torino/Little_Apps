// rnum2.C - Roman objects, mutable
#include <iostream.h>
#include "Roman2.h"

int main()
{
	Roman r1 = 5719;
	cout << r1.getnum() << " is " << r1.getroman() << endl;
	return 0;
}

/**************************************************************************

$ rnum2
5719 is WDCCXIX

*/
