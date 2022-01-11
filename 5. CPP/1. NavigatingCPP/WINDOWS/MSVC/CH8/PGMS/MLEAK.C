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
A constr(object): 0x007606F0
B constr(object, data): 0x00760704 0x00760710
B constr(object, data): 0x00760708 0x00760720
B destr(object, data): 0x00760708 0x00760720
B destr(object, data): 0x00760704 0x00760710
Memory Leak:
	Filename: mleak.c
	Line Number: 30
	Pointer address: 0x007606F0
Memory Leak:
	Filename: mleak.c
	Line Number: 16
	Pointer address: 0x00760710
Memory Leak:
	Filename: mleak.c
	Line Number: 16
	Pointer address: 0x00760720

abnormal program termination

*/
