// sgplace.c - static and global array placement
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

char buf1[1024];								// global character buffer
static char buf2[1024];							// static character buffer

int main() {
	 A *p = new (buf1) A;							// new(sizeof(A), buf1)
	 A *q = new (buf2) A[5];						// new[](5*sizeof(A), buf2)
	 cout << "p = " << p << "  buf1 = " << (void *)buf1 << endl;
	 cout << "q = " << q << "  buf2 = " << (void *)buf2 << endl;

	 p->~A();											// explicit destructor
	 for (int i = 4; i >= 0; i--)
	 	q[i].~A();										// explict destructor
	 return 0;
}

/**********************************************************************

$ sgplace 
A constr: 0x10013130
global operator new[](addr): 0x100135b8 40
A constr: 0x10013140
A constr: 0x10013150
A constr: 0x10013160
A constr: 0x10013170
A constr: 0x10013180
p = 0x10012188  buf1 = 0x10012188
q = 0x100135b8  buf2 = 0x10012588
A destr: 0x10013130
global operator delete[]: 0x10013130
A destr: 0x10013180
global operator delete[]: 0x10013180
A destr: 0x10013170
global operator delete[]: 0x10013170
A destr: 0x10013160
global operator delete[]: 0x10013160
A destr: 0x10013150
global operator delete[]: 0x10013150
A destr: 0x10013140
global operator delete[]: 0x10013140

*/
