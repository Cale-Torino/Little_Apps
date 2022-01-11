// args.C - single argument overloading resolution
#include <iostream.h>
#include "Roman.h"

class Act {									// Act class
private:
	Roman num;								// Roman object
public:
	Act(const Roman & r) : num(r) { }
	const char *getact() const { return num.getroman(); }
};

void f(unsigned short c) { cout << "unsigned short " << c << endl; }
void f(int n) { cout << "int " << n << endl; }
void f(void *p) { cout << "void * " << p << endl; }
void f(const Act & a) { cout << "Act " << a.getact() << endl; }
void f(...) { cout << "ellipsis" << endl; }

int main()
{
	unsigned short b = 100;
	const int n = 12;
	short s = 50;
	double v = 5.6; 
	double *p = &v;
	Roman m = 13;											// Roman object
	static struct { long m; } w = { 25 };			// structure

	f(b);										// f(unsigned short), exact match
	f(n);										// f(int), trivial conversion
	f(s);										// f(int), promotion
	f(p);										// f(void *), standard conversion
	f(m);										// f(const Act &), user-defined conversion
	f(w);										// f(...), ellipsis, no match above
	return 0;
}

/**********************************************************************

$ args 
unsigned short 100
int 12
int 50
void * 0xffe8
Act XIII
ellipsis

*/
