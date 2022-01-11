// gnd1.c - global new and delete overloading
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
global operator new[](addr): 0x10013348 400
global operator new[](addr): 0x100138e8 320
global operator delete[]: 0x100131b0
global operator delete[]: 0x10013348
global operator delete[]: 0x100138e8

*/
