// gnd2.c - global overriding of class specific new and delete 
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
public:
    void *operator new (size_t size) {
		void *p = malloc(size);
		cout << "A::operator new: " << p << ' ' << size << endl;
		return p;
	}

   //void *operator new [] (size_t size) {
		//void *p = malloc(size);
      //cout << "A::operator new[]: " << p << ' ' << size << endl;
      //return p;
   //}

	void *operator new (size_t size, void *) {
		void *p = malloc(size);
		cout << "A::operator new(addr): " << p << ' ' << size << endl;
		return p;
	}

   //void *operator new [] (size_t size, void *) {
		//void *p = malloc(size);
      //cout << "A::operator new[](addr): " << p << ' ' << size << endl;
      //return p;
   //}

	void operator delete(void *p) {
		cout << "A::operator delete: " << p << endl;
		free(p);
	}

	//void operator delete [] (void *p) {
		//cout << "A::operator delete[]: " << p << endl;
		//free(p);
	//}
};

static char spot[1024];

int main()
{
    A *pa = new A;                          // new(sizeof(A))
    A *pb = new A[50];                   // new[](50*sizeof(A))
    A *pc = new (spot) A;              // new(sizeof(A), spot)
    A *pd = new (spot) A[50];        // new[](50*sizeof(A), spot)

    delete pa;
    delete [] pb;
    delete pc;
    delete [] pd;
    return 0;
}

/**********************************************************************

$ gnd2 
A::operator new: 0x10013130 1
A::operator new(addr): 0x10013140 1
global operator new[](addr): 0x100135f8 50
A::operator delete: 0x10013130
global operator delete[]: 0x100135b8
A::operator delete: 0x10013140
global operator delete[]: 0x100135f8

*/
