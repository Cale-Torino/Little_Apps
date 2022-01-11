// gnd3.c - global overriding of class specific new and delete 
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
    A *pa = ::new (spot) A;              // new(sizeof(A), spot)
    A *pb = ::new (spot) A[50];        // new[](50*sizeof(A), spot)

    ::delete pa;
    ::delete [] pb;
    return 0;
} 

/**********************************************************************

$ gnd3 
global operator new(addr): 0x19c2 1
global operator new[](addr): 0x19ca 50
global operator delete: 0x19c2
global operator delete[]: 0x19ca
global operator delete: 0x1968
global operator delete: 0x19ba
global operator delete[]: 0x1300
global operator delete: 0x12d8

*/
