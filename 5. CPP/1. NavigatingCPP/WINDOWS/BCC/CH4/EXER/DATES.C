// dates.C - Date class
#include <iostream.h>
#include "Date.h"

int main()
{
	try {
		 Date d1(7,31,1996);								// set date
		 d1.print();										// display date
		 d1.tomorrow();									// display next day
		 d1.yesterday();									// display previous day
		 d1.set(10,31,1900);								// change date
		 d1.print();										// display date

		 Date d2;											// set to today's date
		 d2.print();										// display date
		 Date d3(9,1,1900);								// set date
		 d3.yesterday();									// display previous day

		 Date d4(7,3,1996); 								// set date
		 cout << d4.month() << '/';					// display month
		 cout << d4.day() << '/';						// display day
		 cout << d4.year() << endl; 					// display year

		 d4.month(12);										// set month
		 d4.day(31);										// set day
		 d4.year(1999);									// set day
		 Date d5 = d4;										// create new date
		 d5.print();										// display date

		 Date d6(13,1,1);									// illegal date - bad month
	}

	catch (const DateErr & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*************************************************************************

7,31,1996
8,1,1996
7,30,1996
10,31,1900
3,18,97
8,31,1900
7/3/1996
12,31,1999
13 is an illegal month

*/
