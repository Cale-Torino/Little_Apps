// struct3.C - nested structures
#include <iostream.h>

struct X {										// outer X
	struct Y {									// Y nested in outer X
		struct X {								// inner X nested in Y
			int i;								// member of inner X
		};
		X mystuff;								// member of Y
		int j;									// member of Y
	};
	Y stuff;										// member of outer X
	int k;										// member of outer X
};
	
int main()
{
	X a;
	a.k = 3;										// a.i and a.j are illegal
	cout << a.k << endl;
	return 0;
}

/*******************************************************************

$ struct3
3

*/
