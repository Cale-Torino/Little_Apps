// cast7.c - new casts vs. old style casts
#include <iostream.h>

int f(int *);
double v = 12;
double *pv = &v;

int main()
{
	f((int *)pv);								// old style cast compiles
	//f(static_cast<int *>(pv));				// static cast is illegal
	return 0;
}

int f(int * pd) {
	cout << *pd << endl;
	return *pd;
}

/**********************************************************************

$ cast7
0

*/
