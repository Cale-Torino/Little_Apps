// tcomp.c - template composition
#include "String.h"

template <class TYPE> class A { };
template <class TYPE> class B { };
template <class TYPE> class C { };

int main()
{
	A<String> c1;								// String container
	A< B<String > > c2;							// B<String> container
	A< B< C<String> > > c3;						// B<C<String>> container
	A< A< A<String> > > c4;						// A<A<String>> container

	cout << &c1 << ' ' << &c2 << ' ' << &c3 << ' ' << &c4 << endl;
	return 0;
}

/**********************************************************************

$ tcomp 
0x7fff2ef0 0x7fff2ef8 0x7fff2f00 0x7fff2f08

*/
