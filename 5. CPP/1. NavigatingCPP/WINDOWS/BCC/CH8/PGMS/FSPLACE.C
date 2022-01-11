// fsplace - free store placement
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

char *spot1 = new char[sizeof(A)];				// new(sizeof(A))
char *spot2 = new char[5*sizeof(A)];			// new[](5*sizeof(A)*sizeof(char))

int main() {
	 A *p = new (spot1) A;								// new(sizeof(A), spot1)
	 A *q = new (spot2) A[5];							// new[](5*sizeof(A), spot2)
	 cout << "p = " << p << "  spot1 = " << (void *)spot1 << endl;
	 cout << "q = " << q << "  spot2 = " << (void *)spot2 << endl;

	 p->~A();												// explicit destructor
	 for (int i = 4; i >= 0; i--)
	 	q[i].~A();											// explict destructor
	 delete [] spot1;										// delete free store placement
	 delete [] spot2;										// delete free store placement
	 return 0;
}

/**********************************************************************

$ fsplace 
global operator new(addr): 0x1640 4
A constr: 0x1648
global operator new[](addr): 0x1650 24
A constr: 0x166c
A constr: 0x1674
A constr: 0x167c
A constr: 0x1684
A constr: 0x168c
p = 0x1640  spot1 = 0x15c6
q = 0x1652  spot2 = 0x15ce
A destr: 0x1648
global operator delete[]: 0x1648
A destr: 0x168c
global operator delete[]: 0x168c
A destr: 0x1684
global operator delete[]: 0x1684
A destr: 0x167c
global operator delete[]: 0x167c
A destr: 0x1674
global operator delete[]: 0x1674
A destr: 0x166c
global operator delete[]: 0x166c
global operator delete[]: 0x15c6
global operator delete[]: 0x15ce
global operator delete: 0x15e6
global operator delete: 0x1638
global operator delete[]: 0x0f5e
global operator delete: 0x0f36

*/
