// gnd1.c - global new and delete overloading
#include <iostream.h>
#include <malloc.h>

// NOTE: Borland doesn't seem to have a new.h

// NOTE: Borland doesn't let you overload global new 
// void *operator new (size_t size) {
   //cout << "global operator new: " << size << endl;
   //return malloc(size);
//}

// NOTE: Borland doesn't let you overload global new []
//void *operator new [] (size_t size) {
   //cout << "global operator new []: " << size << endl;
   //return malloc(size);
//}

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

static char spot[1024];

int main()
{
    double *pa = new double;                          // new(sizeof(double))
    double *pb = new double[50];                   // new[](50*sizeof(double))
    double *pc = new (spot) double;              // new(sizeof(double), spot)
    double *pd = new (spot) double[50];        // new[](50*sizeof(double), spot)
    double (*pe)[8] = new (spot) double[5][8]; // new[](40*sizeof(double), spot)

    delete pa;
    delete [] pb;
    delete pc;
    delete [] pd;
    delete [] pe;
    return 0;
}

/**********************************************************************

$ gnd1 
global operator new(addr): 0x1fc0 8
global operator new[](addr): 0x1fcc 400
global operator new[](addr): 0x2160 320
global operator delete: 0x1e20
global operator delete[]: 0x1e2c
global operator delete: 0x1fc0
global operator delete[]: 0x1fcc
global operator delete[]: 0x2160
global operator delete: 0x1dc6
global operator delete: 0x1e18
global operator delete[]: 0x175e
global operator delete: 0x1736

*/
