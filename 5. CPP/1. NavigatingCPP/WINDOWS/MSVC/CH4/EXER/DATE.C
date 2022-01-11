// Date.C - Date implementation
#include <iostream.h>
#include <stdio.h>
#include <time.h>
#include "Date.h"

Date::Date(int mon, int dy, int yr) { 
	setmon(mon);
	setday(mon, dy);
	setyear(yr);
}

Date::Date() {										// today's date (under UNIX) 
   long t = time(0);
	tm *pt  = localtime(&t);
	cmonth = pt->tm_mon+1; 
	cday = pt->tm_mday;
	cyear = pt->tm_year;
}

void Date::setmon(int m) { 
	if (m >=1 && m <= 12)
		cmonth = m;
	else {
		char buf[80];
		sprintf(buf, "%d is an illegal month", m);
		throw DateErr(buf);
	}
}

void Date::setday(int m, int d) { 
	if (d <= mdays(m))
		cday = d;
	else {
		char buf[80];
		sprintf(buf, "%d is an illegal day for month %d", d, m);
		throw DateErr(buf);
	}
}

void Date::setyear(int yr) { 
	if (yr > 0)
		cyear = yr;
	else { 
		char buf[80];
		sprintf(buf, "%d is an illegal year", yr);
		throw DateErr(buf);
	}
}

void Date::print() const { 
		cout << cmonth << ',' << cday << ',' << cyear << endl;
}

void Date::set(int mon, int dy, int yr) { 
	setmon(mon);
	setday(mon, dy);
	setyear(yr);
}

int Date::month() const { return cmonth; }

void Date::month(int mon) {
	setmon(mon);
}

int Date::day() const { return cday; }

void Date::day(int dy) {
	setday(cmonth, dy);
}

int Date::year() const { return cyear; }

void Date::year(int yr) {
	setyear(yr);
}

int Date::mdays(int mon) const {
   static const int dpm[] = { 31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31 };
   if (mon == 2 && leapyear())
      return 29;
   else
      return dpm[mon - 1];
}

bool Date::leapyear() const {
   return (cyear % 4 == 0 && cyear % 100 != 0) || cyear % 400 == 0;
}

void Date::tomorrow() const {
	int nmonth, nday, nyear;

   if (cday != mdays(cmonth)) {
      nday = cday + 1;								// not end of month
      nmonth = cmonth;
      nyear = cyear;
   }
   else if (cmonth != 12) {
      nday = 1;										// not end of year
      nmonth = cmonth + 1;
      nyear = cyear;
   }
   else {												// last day of year
      nday = 1;
      nmonth = 1;
      nyear = cyear + 1;
   }
	cout << nmonth << ',' << nday << ',' << nyear << endl;
}

void Date::yesterday() const {
	int nmonth, nday, nyear;

   if (cday != 1) {
      nday = cday - 1;								// not first of month
      nmonth = cmonth;
      nyear = cyear;
   }
   else if (cmonth != 1) {
      nmonth = cmonth - 1;
      nday = mdays(nmonth);						// not first of year
      nyear = cyear;
   }
   else {												// first day of year
      nday = 31;
      nmonth = 12;
      nyear = cyear - 1;
   }
	cout << nmonth << ',' << nday << ',' << nyear << endl;
}
