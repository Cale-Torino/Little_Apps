// objects.C - Static, auto, and free store objects
#include <iostream.h>
#include <stdlib.h>
#include "Roman3.h"

Roman num1 = 1950;								// global - program scope
static Roman num2 = 1960;						// external static - file scope

void obj() {
	cout << "obj() called" << endl;
	Roman num3 = 1970;								// stack (automatic)
	static Roman num4 = 1980;						// internal static - data area
	Roman *num5 = new Roman(1990);				// allocate in free store
	delete num5;										// deallocate from free store
	cout << "obj() returned" << endl;			
}

void done () { cout << "done() called" << endl; }

int main()
{
	atexit(done);										// call done() at exit
	obj();
	obj();
   return 0;
}

/**********************************************************************

$ objects 
Constructor for 1950 (MCML)
Constructor for 1960 (MCMLX)
obj() called
Constructor for 1970 (MCMLXX)
Constructor for 1980 (MCMLXXX)
Constructor for 1990 (MCMXC)
Destructor for 1990 (MCMXC)
obj() returned
Destructor for 1970 (MCMLXX)
obj() called
Constructor for 1970 (MCMLXX)
Constructor for 1990 (MCMXC)
Destructor for 1990 (MCMXC)
obj() returned
Destructor for 1970 (MCMLXX)
done() called
Destructor for 1980 (MCMLXXX)
Destructor for 1960 (MCMLX)
Destructor for 1950 (MCML)

*/
