// date2.C - member function with default argument
#include <iostream.h>

class Date {
private:
	int mon, day, year;
public:
	Date(int m, int d, int y) { mon = m; day = d; year = y; }
	void display(ostream & os = cout) { 
		os << mon << ',' << day << ',' << year << endl;
	}
};

int main()
{
	Date d1(10, 31, 1995);								// Halloween
	Date d2(12, 25, 1995);								// Christmas
	d1.display();
	d2.display(cerr);
	return 0;
}

/**********************************************************************

$ date2 
10,31,1995
12,25,1995

*/
