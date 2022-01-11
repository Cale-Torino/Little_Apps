// scope.C - scope resolution operator
#include <iostream.h>

bool debug = false;												// global scope

int main()
{
	bool debug = true;											// local scope

	cout << "local debug = " << debug << endl;			// display local			
	cout << "global debug = " << ::debug << endl;		// display global
	return 0;														// return to op sys
}

/**********************************************************************

$ scope
local debug = 1
global debug = 0

*/
