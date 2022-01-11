// pxchg1.C - exchange pointers to integers in place using pointers
#include <iostream.h>

int main()
{
	int a = 43, b = 56;
	int *pa = &a, *pb = &b;

	void pxchg(int **, int **);

	cout << *pa << ' ' << *pb << endl;
	pxchg(&pa, &pb);								// pass pointers to pointers
	cout << *pa << ' ' << *pb << endl;
	return 0;
}

void pxchg(int **p, int **q) {				// double indirect pointers
	int *pt = *p;									// exchange pointers
	*p = *q;											
	*q = pt;
}

/*******************************************************************

$ pxchg1
43 56
56 43

*/
