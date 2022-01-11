// pd1.C - place delete with explicit destructors with buffer placement
#include <iostream.h>
#include <malloc.h>

void *operator new (size_t size, void *) {			// placement
	void *p = malloc(size);
   cout << "global operator new(addr): " << p << ' ' << size << endl;
   return p;
}

void *operator new [] (size_t size, void *) {			// placement for arrays
	void *p = malloc(size);
   cout << "global operator new[](addr): " << p << ' ' << size << endl;
   return p;
}

void operator delete(void *p) {
   cout << "global operator delete: " << p << endl;
	free(p);
}

void operator delete [] (void *p) {
   cout << "global operator delete[]: " << p << endl;
	free(p);
}

class Arena {
public:
	Arena();													// default constructor
	~Arena();												// destructor
	void *alloc(size_t);									// allocate size_t bytes
	void dealloc(void *);								// deallocate memory
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
	void *p = ap->alloc(size);							// allocate memory from Arena
   cout << "global operator new(arena): " << p << ' ' << size << endl;
	return p;									// allocate memory from Arena
}

void *operator new[](size_t size, Arena *ap) {		// array of objects
	void *p = ap->alloc(size);							// allocate memory from Arena
   cout << "global operator new[](arena): " << p << ' ' << size << endl;
	return p;									// allocate memory from Arena
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
	void place_delete(int, Arena *ap);
};

void A::place_delete(int nitems = 1, Arena *ap = 0) {
	for (int i = nitems-1; i >= 0; i--)					// loop over A objects
		this[i].~A();											// explicit destructor
	if (ap)														// Arena?
		ap->dealloc(this);									// Arena deallocate
}

int main() {
	 static char buf[sizeof(A)];						// static buffer placement
	 A *p = new (buf) A;									// place A in static buffer
	 cout << "p = " << p << "  buf = " << (void *)buf << endl;

	 p->place_delete();									// delete A object
	 return 0;
}

/**********************************************************************

$ pd1 
global operator new(addr): 0x166e 4
A constr: 0x1676
p = 0x166e  buf = 0x097e
A destr: 0x1676
global operator delete[]: 0x1676
global operator delete: 0x1614
global operator delete: 0x1666
global operator delete[]: 0x0fac
global operator delete: 0x0f84

*/
