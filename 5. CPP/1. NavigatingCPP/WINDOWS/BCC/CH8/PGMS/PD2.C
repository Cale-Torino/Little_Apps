// pd2.C - place delete with explicit destructors with free store placement
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
	 char *spot = new char[5*sizeof(A)];				// free store placement
	 A *q = new (spot) A[5];								// place 5 A's in free store
	 cout << "q = " << q << "  spot = " << (void *)spot << endl;

	 q->place_delete(5);									// delete 5 A objects
	 delete [] spot;										// delete free store placement
	 return 0;
}

/**********************************************************************

$ pd2 
global operator new[](addr): 0x1682 24
A constr: 0x169e
A constr: 0x16a6
A constr: 0x16ae
A constr: 0x16b6
A constr: 0x16be
q = 0x1684  spot = 0x166a
A destr: 0x16be
global operator delete[]: 0x16be
A destr: 0x16b6
global operator delete[]: 0x16b6
A destr: 0x16ae
global operator delete[]: 0x16ae
A destr: 0x16a6
global operator delete[]: 0x16a6
A destr: 0x169e
global operator delete[]: 0x169e
global operator delete[]: 0x166a
global operator delete: 0x1610
global operator delete: 0x1662
global operator delete[]: 0x0fa8
global operator delete: 0x0f80

*/
