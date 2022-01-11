// ex3.c - type * and type *&
#include <iostream.h>

void f(double * d) { cout << "double * = " << *d << endl; }
//void f(double *& d) { cout << "double *& d = " << *d << endl; }

int main()
{
	double m = 3.4, *p = &m;
	double r = 5.6, *q = &r;
	double *& v = q;								// reference to pointer
	//f(p);											// error - ambiguous
	//f(v);											// error - ambiguous
	cout << *p << ' ' << *v << endl;
	return 0;
}

/********************************************************************

$ ex3
3.4 5.6

NOTES:

1. Both calls to f() are illegal because the overloading mechanism cannot 
	tell a void (double *) from a void (double *&). Note that this is 
	essentially TYPE and TYPE &, where TYPE is double *.

*/
