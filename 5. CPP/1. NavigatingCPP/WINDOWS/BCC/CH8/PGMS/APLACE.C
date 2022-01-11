// aplace.c - Arena placement
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

int main() {
	 Arena *Persistent = new Arena;
	 A *p = new (Persistent) A;					// new(sizeof(A), Persistent)
	 A *q = new (Persistent) A[5];				// new[](5*sizeof(A), Persistent)
	 cout << "p = " << p << "  Persistent = " << Persistent << endl;
	 cout << "q = " << q << "  Persistent = " << Persistent << endl;

	 p->~A();												// explicit destructor
	 for (int i = 4; i >= 0; i--)
	 	q[i].~A();											// explict destructor
	 Persistent->dealloc(p);							// delete arena placement
	 Persistent->dealloc(q);							// delete arena placement
	 delete Persistent;
	 return 0;
}

/**********************************************************************

$ aplace 
Arena constr
Arena alloc(addr): 0x16a2 4
global operator new(arena): 0x16a2 4
A constr: 0x16aa
Arena alloc(addr): 0x16b2 24
global operator new[](arena): 0x16b2 24
A constr: 0x16ce
A constr: 0x16d6
A constr: 0x16de
A constr: 0x16e6
A constr: 0x16ee
p = 0x16a2  Persistent = 0x169a
q = 0x16b4  Persistent = 0x169a
A destr: 0x16aa
global operator delete[]: 0x16aa
A destr: 0x16ee
global operator delete[]: 0x16ee
A destr: 0x16e6
global operator delete[]: 0x16e6
A destr: 0x16de
global operator delete[]: 0x16de
A destr: 0x16d6
global operator delete[]: 0x16d6
A destr: 0x16ce
global operator delete[]: 0x16ce
Arena delalloc: 0x16a2
Arena delalloc: 0x16b4
Arena destr
global operator delete: 0x169a
global operator delete: 0x1640
global operator delete: 0x1692
global operator delete[]: 0x0fd8
global operator delete: 0x0fb0

*/
