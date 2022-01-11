// arrays.C - Arrays of class objects
#include <iostream.h>
#include <assert.h>
#include "Roman4.h"

int main()
{
	const int max = 3;
	Roman *r = new Roman[max];
	assert(r);

	delete [] r;							// release all Roman objects
   return 0;
}

/**********************************************************************

$ arrays 
Constructor 1 for 1 (I)
Constructor 2 for 2 (II)
Constructor 3 for 3 (III)
Destructor 3 for 3 (III)
Destructor 2 for 2 (II)
Destructor 1 for 1 (I)

*/
