// gnd2.c - global overriding of class specific new and delete 
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
A::operator new: 0x1a16 1
A::operator new(addr): 0x1a54 1
global operator new[](addr): 0x1a5c 50
A::operator delete: 0x1a16
global operator delete[]: 0x1a1e
A::operator delete: 0x1a54
global operator delete[]: 0x1a5c
global operator delete: 0x19bc
global operator delete: 0x1a0e
global operator delete[]: 0x1354
global operator delete: 0x132c

*/
