// ex4.c - Legal and illegal overloading groups
#include <iostream.h>

// legal - Type * and const Type *const
void f(double *d) { cout << "double * d = " << *d << endl; }
void f(const double *const d) { cout << "const double * = " << *d << endl; }

// illegal - const Type and Type &
//void g(const double d) { cout << "const double = " << d << endl; }
//void g(double & rd) { cout << "double & = " << rd << endl; }

// illegal - const Type & and Type
//void h(const double & rd) { cout << "const double & = " << rd << endl; }
//void h(double d) { cout << "double = " << d << endl; }

// legal - const Type and const Type *const
void j(const double d) { cout << "const double d = " << d << endl; }
void j(const double *const d) { cout << "const double * = " << *d << endl; }

int main()
{
	const double m = 3.4, *p = &m;
	double r = 5.6, *q = &r;
	f(p);												// call f(const double *)
	f(q);												// call f(double *)

	//g(m);											// ambiguous, which g()?
	//g(r);											// ambiguous, which g()?

	//h(m);											// ambiguous, which h()?
	//h(r);											// ambiguous, which h()?

	j(m);												// call j(const double)
	j(p);												// call j(const double *)
	return 0;
}

/************************************************************************

$ ex4
const double * = 3.4
double * d = 5.6
const double d = 3.4
const double * = 3.4

*/
