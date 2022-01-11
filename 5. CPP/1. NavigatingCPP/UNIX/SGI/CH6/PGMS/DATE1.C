// date1.C - separate member functions
#include <iostream.h>

class Date {
private:
	int mon, day, year;
public:
	Date(int m, int d, int y) { mon = m; day = d; year = y; }
	void display()	{									// display date on cout
		cout << mon << ',' << day << ',' << year << endl; 
	}
	void displayerr()	{								// display date on cerr
		cerr << mon << ',' << day << ',' << year << endl; 
	}
};

int main()
{
	Date d1(10, 31, 1995);								// Halloween
	Date d2(12, 25, 1995);								// Christmas
	d1.display();
	d2.displayerr();
	return 0;
}

/**********************************************************************

$ date1 
10,31,1995
12,25,1995

*/
