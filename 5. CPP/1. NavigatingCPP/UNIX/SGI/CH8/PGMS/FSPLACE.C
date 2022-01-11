// fsplace - free store placement
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

char *spot1 = new char[sizeof(A)];			// new(sizeof(A))
char *spot2 = new char[5*sizeof(A)];		// new[](5*sizeof(A)*sizeof(char))

int main() {
	 A *p = new (spot1) A;					// new(sizeof(A), spot1)
	 A *q = new (spot2) A[5];				// new[](5*sizeof(A), spot2)
	 cout << "p = " << p << "  spot1 = " << (void *)spot1 << endl;
	 cout << "q = " << q << "  spot2 = " << (void *)spot2 << endl;

	 p->~A();									// explicit destructor
	 for (int i = 4; i >= 0; i--)
	 	q[i].~A();								// explict destructor
	 delete [] spot1;							// delete free store placement
	 delete [] spot2;							// delete free store placement
	 return 0;
}

/**********************************************************************

$ fsplace 
A constr: 0x10013140
global operator new[](addr): 0x100135e8 40
A constr: 0x10013150
A constr: 0x10013160
A constr: 0x10013170
A constr: 0x10013180
A constr: 0x10013190
p = 0x10013130  spot1 = 0x10013130
q = 0x100135e8  spot2 = 0x100131b0
A destr: 0x10013140
global operator delete[]: 0x10013140
A destr: 0x10013190
global operator delete[]: 0x10013190
A destr: 0x10013180
global operator delete[]: 0x10013180
A destr: 0x10013170
global operator delete[]: 0x10013170
A destr: 0x10013160
global operator delete[]: 0x10013160
A destr: 0x10013150
global operator delete[]: 0x10013150
global operator delete[]: 0x10013130
global operator delete[]: 0x100131b0

*/
