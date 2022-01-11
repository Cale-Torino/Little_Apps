// pd3.C - place delete with explicit destructors with Arena placement
#include <iostream.h>
#include <malloc.h>

void *operator new [] (size_t size, void *) {			// placement for arrays
	void *p = malloc(size);
	cout << "global operator new[](addr): " << p << ' ' << size << endl;
	return p;
}

void operator delete [] (void *p) {
	cout << "global operator delete[]: " << p << endl;
	free(p);
}

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
		this[i].~A();									// explicit destructor
	if (ap)												// Arena?
		ap->dealloc(this);								// Arena deallocate
}

int main() {
	 Arena *Persistent = new Arena;
	 A *r = new (Persistent) A[5];						// place 5 A's in Arena
	 cout << "r = " << r << "  Persistent = " << Persistent << endl;

	 r->place_delete(5, Persistent);					// delete 5 A objects
	 delete Persistent;
	 return 0;
}

/**********************************************************************

$ pd3 
Arena constr
Arena alloc(addr): 0x100145b8 40
global operator new[](arena): 0x100145b8 40
A constr: 0x10014140
A constr: 0x10014150
A constr: 0x10014160
A constr: 0x10014170
A constr: 0x10014180
r = 0x100145b8  Persistent = 0x10014130
A destr: 0x10014180
global operator delete[]: 0x10014180
A destr: 0x10014170
global operator delete[]: 0x10014170
A destr: 0x10014160
global operator delete[]: 0x10014160
A destr: 0x10014150
global operator delete[]: 0x10014150
A destr: 0x10014140
global operator delete[]: 0x10014140
Arena delalloc: 0x100145b8
Arena destr

*/
