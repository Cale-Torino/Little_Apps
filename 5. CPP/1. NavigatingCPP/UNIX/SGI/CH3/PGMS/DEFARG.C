// defarg.c - default arguments
#include <iostream.h>
#include <string.h>
#include <math.h>

static double dval = 3.4;							// external static
double val = 5.6;

void sub() {
	enum { max = 100 };								// enumeration
	int m1 = 10;										// local integer
	static int m2 = 6;								// local (static) integer
	void f(double s = sin(.5));					// legal - function call
	//void g(int i = m1);								// illegal - local
	void h(int m = max);								// legal - enumeration
	void w(int j = val);								// legal - global
	void x(double d = dval);						// legal - external static
	//void y(int k = m2);								// legal - local static
	//void s(char *p, int len = strlen(p));		// illegal - local
	cout << m1 << ' ' << m2 << endl;
}

int main()
{
	sub();
	return 0;
}

/*******************************************************************

$ defarg
10 6

*/
