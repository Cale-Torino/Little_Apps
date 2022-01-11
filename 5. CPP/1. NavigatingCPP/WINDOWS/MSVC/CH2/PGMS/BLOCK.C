// block.c - block scope
#include <iostream.h>

int main()
{													// start of outer block
	int i = 1;									// local i
	{												// start of inner block
		int j = 2;								// local j
		cout << i << ' ' << j << endl;	// legal for i and j
	}												// end of inner block
  	//cout << i << ' ' << j << endl;		// legal for i, illegal for j
	return 0;
}													// end of outer block

/**********************************************************************

$ block
1 2

*/
