// void2.c - const void pointers
#include <iostream.h>

int main()
{
	const float m = 5.5;					// constant float
	float n = 3.3;							// float

	const void *r;							// r is a pointer to const void
	r = &m;									// legal - r points to float
	r = &n;									// legal - r points to const float
	//*r = 7.5;								// illegal - *r is const void

	void *q;									// q is a void pointer
	q = &n;									// legal - q points to float
	//q = &m;								// illegal - m is a const float
	//*q = 7.5;								// illegal - *q is void

	void *const v = &n;					// v is a constant pointer to void
	//void *const w = &m;				// illegal - m is a const float

	const void *const s = &n;			// s is a constant pointer to const void
	const void *const t = &m;			// t is a constant pointer to const void
	//s = r;									// illegal - assignment to const pointer
	//v = w;									// illegal - assignment to const pointer
	//cout << *s << *t << endl;		// illegal - *s is const void
	//cout << *v << endl;				// illegal - *v is void

	cout << v << ' ' << (void *)s << ' ' << q << ' ' 
			<< (void *)r << ' ' << (void *)t << endl;
	return 0;
}

/**********************************************************************

$ void2
0xffee 0xffee 0xffee 0xffee 0xfff2

*/
