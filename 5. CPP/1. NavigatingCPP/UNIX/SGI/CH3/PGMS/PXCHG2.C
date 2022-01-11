// pxchg2.C - exchange pointers to integers in place using references
#include <iostream.h>

int main()
{
	int a = 43, b = 56;
	int *pa = &a, *pb = &b;

	void pxchg(int *&, int *&);				// references to pointers

	cout << *pa << ' ' << *pb << endl;
	pxchg(pa, pb);
	cout << *pa << ' ' << *pb << endl;
	return 0;
}

void pxchg(int *& p, int *& q) {				// references to pointers
	int *pt = p;									// exchange pointers
	p = q;											
	q = pt;
}

/*******************************************************************

$ pxchg2
43 56
56 43

*/
