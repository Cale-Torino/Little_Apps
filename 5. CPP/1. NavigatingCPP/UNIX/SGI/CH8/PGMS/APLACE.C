// aplace.c - Arena placement
#include <iostream.h>
#include <malloc.h>
#include <new.h>

void *operator new [] (size_t size, void *) {			// placement for arrays
	void *p = malloc(size);
   cout << "global operator new[](addr): " << p << ' ' << size << endl;
   return p;
}

void operator delete [] (void *p) {
   cout << "global operator delete[]: " << p << endl;
	free(p);
}

class A {
private:
	int *p;
	int size;
public:
	A(int len = 0) { 
		p = new int[size=len]; 
		cout << "A constr: " << p << endl;
	}
	~A() { 
		cout << "A destr: " << p << endl; 
		delete [] p; 
	}
};

class Arena {
public:
	Arena();										// default constructor
	~Arena();										// destructor
	void *alloc(size_t);							// allocate size_t bytes
	void dealloc(void *);							// deallocate memory
};

Arena::Arena() { cout << "Arena constr" << endl; }
Arena::~Arena() { cout << "Arena destr" << endl; }
void *Arena::alloc(size_t size) {
	void *p = malloc(size);
	cout << "Arena alloc(addr): " << p << ' ' << size << endl;
	return p;
}

void Arena::dealloc(void *p) {
	cout << "Arena delalloc: " << p << endl;
	free(p);
}

void *operator new(size_t size, Arena *ap) {			// single object
	void *p = ap->alloc(size);					// allocate memory from Arena
	cout << "global operator new(arena): " << p << ' ' << size << endl;
	return p;									// allocate memory from Arena
}

void *operator new[](size_t size, Arena *ap) {		// array of objects
	void *p = ap->alloc(size);					// allocate memory from Arena
	cout << "global operator new[](arena): " << p << ' ' << size << endl;
	return p;									// allocate memory from Arena
}

int main() {
	 Arena *Persistent = new Arena;
	 A *p = new (Persistent) A;				// new(sizeof(A), Persistent)
	 A *q = new (Persistent) A[5];			// new[](5*sizeof(A), Persistent)
	 cout << "p = " << p << "  Persistent = " << Persistent << endl;
	 cout << "q = " << q << "  Persistent = " << Persistent << endl;

	 p->~A();										// explicit destructor
	 for (int i = 4; i >= 0; i--)
	 	q[i].~A();									// explict destructor
	 Persistent->dealloc(p);						// delete arena placement
	 Persistent->dealloc(q);						// delete arena placement
	 delete Persistent;
	 return 0;
}

/**********************************************************************

$ aplace 
Arena constr
Arena alloc(addr): 0x10014140 8
global operator new(arena): 0x10014140 8
A constr: 0x10014150
Arena alloc(addr): 0x100145b8 40
global operator new[](arena): 0x100145b8 40
A constr: 0x10014160
A constr: 0x10014170
A constr: 0x10014180
A constr: 0x10014190
A constr: 0x100141a0
p = 0x10014140  Persistent = 0x10014130
q = 0x100145b8  Persistent = 0x10014130
A destr: 0x10014150
global operator delete[]: 0x10014150
A destr: 0x100141a0
global operator delete[]: 0x100141a0
A destr: 0x10014190
global operator delete[]: 0x10014190
A destr: 0x10014180
global operator delete[]: 0x10014180
A destr: 0x10014170
global operator delete[]: 0x10014170
A destr: 0x10014160
global operator delete[]: 0x10014160
Arena delalloc: 0x10014140
Arena delalloc: 0x100145b8
Arena destr

*/
