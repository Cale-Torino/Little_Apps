// mleak.C - program with memory leaks
#include <iostream.h>
#include <stdlib.h>
#include "New.h"

class A {
public:
	A() { cerr << "A constr(object): " << this << endl; }
	~A() { cerr << "A destr(object): " << this << endl; }
};

class B {
private:
	int *p;
public:
	B() { p = New int;						// line 16 
		cerr << "B constr(object, data): " << this << ' ' << p << endl;
	}
	~B() { 
		cerr << "B destr(object, data): " << this << ' ' << p << endl;
		// No delete, memory leak
	}
};

int main() 
{
	try {
		 atexit(mleak_check);					// check for memory leaks at exit

		 A *p1 = New A;							// line 30, no delete, memory leak
		 B *p2 = New B[2];						// allocate array
		 delete [] p2;								// deallocate array
	}
	catch (const NewError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ mleak 
A constr(object): 0x10014130
B constr(object, data): 0x10014140 0x10014150
B constr(object, data): 0x10014144 0x10014160
Memory Leak:
	Filename: mleak.C
	Line Number: 30
	Pointer address: 0x10014130
Memory Leak:
	Filename: mleak.C
	Line Number: 31
	Pointer address: 0x10014140
Memory Leak:
	Filename: mleak.C
	Line Number: 16
	Pointer address: 0x10014150
Memory Leak:
	Filename: mleak.C
	Line Number: 16
	Pointer address: 0x10014160

*/
