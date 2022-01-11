// sgplace.c - static and global array placement
#include <iostream.h>
#include <malloc.h>

void *operator new (size_t size, void *) {			// placement
	void *p = malloc(size);
   cout << "global operator new(addr): " << p << ' ' << size << endl;
   return p;
}

//void *operator new [] (size_t size, void *) {			// placement for arrays
	//void *p = malloc(size);
   //cout << "global operator new[](addr): " << p << ' ' << size << endl;
   //return p;
//}

void operator delete(void *p) {
   cout << "global operator delete: " << p << endl;
	free(p);
}

//void operator delete [] (void *p) {
   //cout << "global operator delete[]: " << p << endl;
	//free(p);
//}

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

char buf1[1024];									// global character buffer
static char buf2[1024];							// static character buffer

int main() {
	 A *p = new (buf1) A;								// new(sizeof(A), buf1)
	 A *q = new (buf2) A[5];							// new[](5*sizeof(A), buf2)
	 cout << "p = " << p << "  buf1 = " << (void *)buf1 << endl;
	 cout << "q = " << q << "  buf2 = " << (void *)buf2 << endl;

	 p->~A();												// explicit destructor
	 for (int i = 4; i >= 0; i--)
	 	q[i].~A();											// explict destructor
	 return 0;
}

/**********************************************************************

$ sgplace 
global operator new(addr): 0x1e14 4
A constr: 0x1e1c
global operator new[](addr): 0x1e24 24
A constr: 0x1e40
A constr: 0x1e48
A constr: 0x1e50
A constr: 0x1e58
A constr: 0x1e60
p = 0x1e14  buf1 = 0x0928
q = 0x1e26  buf2 = 0x0d28
A destr: 0x1e1c
global operator delete[]: 0x1e1c
A destr: 0x1e60
global operator delete[]: 0x1e60
A destr: 0x1e58
global operator delete[]: 0x1e58
A destr: 0x1e50
global operator delete[]: 0x1e50
A destr: 0x1e48
global operator delete[]: 0x1e48
A destr: 0x1e40
global operator delete[]: 0x1e40
global operator delete: 0x1dba
global operator delete: 0x1e0c
global operator delete[]: 0x1752
global operator delete: 0x172a

*/
