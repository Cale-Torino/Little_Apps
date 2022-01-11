// nextday.C - determine tomorrow's date
#include <iostream.h>
#include <stdlib.h>

struct date {
   int month, day, year;
};

int main()
{
    static date d1 = { 7, 30, 1992 };
    static date d2 = { 12, 31, 1989 };
    static date d3 = { 2, 28, 1992 };

    date next, & nextday(const date &);
    
    next = nextday(d1);
    cout << next.month << ',' << next.day << ',' << next.year << endl;

    next = nextday(d2);
    cout << next.month << ',' << next.day << ',' << next.year << endl;

    next = nextday(d3);
    cout << next.month << ',' << next.day << ',' << next.year << endl;
    return 0;
}

date & nextday(const date & d)
{
   int mdays(const date &);
   static date today;

   if (d.day != mdays(d)) {
      today.day = d.day + 1;                  // not end of month
      today.month = d.month;
      today.year = d.year;
   }
   else if (d.month != 12) {
      today.day = 1;                          // not end of year
      today.month = d.month + 1;
      today.year = d.year;
   }
   else {                                     // December 31
      today.day = 1;
      today.month = 1;
      today.year = d.year + 1;
   }
   return today;
}

int mdays(const date & today) 
{
   bool leapyear(int);

   static const int dpm[] = { 31, 28, 31, 30, 31, 30,
                                  31, 31, 30, 31, 30, 31 };

   if (today.month == 2 && leapyear(today.year))
      return 29;
   else
      return dpm[today.month - 1];
}

bool leapyear(int year)
{
   if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      return 1;
   else
      return 0;
}

/************************************************************************

$ nextday
7,31,1992
1,1,1990
2,29,1992

*/
