// fs1.C - Fixed Strings
#include <iostream.h>
#include "FString1.h"

int main()
{
	try {
		FString<80> s1;							// 80 char string
		FString<80> s2 = "hello";				// initialized 80 char string
		FString<80> s3 = s2;						// FString copy initialization
		s1 = s3;										// FString assignment
		cout << s1 << " has " << s1.length() << " characters " << endl;

		FString<256> s4 = "goodbye";			// initialized 256 char string			
		cout << s4 << " has " << s4.length() << " characters " << endl;
		//s4 = s1;									// illegal, wrong lengths
		s2[0] = 'j';
		cout << s2 << endl;
		//FString<10> s5 = "string too long";		// throws exception			
		s2[100] = 'x';								// throws exception
	}
	catch (const FStringError & e) {			// FString errors
		e.response();
		return 1;
	}
	return 0;
}

/******************************************************************************

$ fs1
hello has 5 characters 
goodbye has 7 characters 
jello
FString: index 100 out of bounds

NOTES:
1. The FString class is reasonably efficient because it makes NO calls to
	operator new or delete.  Instead of a pointer, the class uses an internal
	character array to hold NULL terminteed Strings. The length of this array
	is the value of the template constant expression parameter plus 1 for
	the NULL byte. Note that FString does NOT require the full boilerplate.
	Copy initiliazation and assignment are free because the compiler 
	copies the internal arrays implicitly.

2. The downside of this design is that you can only do copy initialization
	and assignments between FString objects that are the same length.  The
	compiler checks the template size parameter and issues compilation errors
	if they are not the same.  The same is true if you overload operator+()
	and operator-() for concatenation.

*/
