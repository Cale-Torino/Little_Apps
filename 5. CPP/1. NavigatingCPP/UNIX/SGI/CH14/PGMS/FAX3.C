// fax3.C - Virtual Bases, object layout and conversions
#include <iostream.h>
#include "Machine.h"
#include "PtrList.h"

void info1(Machine &) { cout << "info1() called" << endl; }
void info2(Copier &) { cout << "info2() called" << endl; }
void info3(Fax &) { cout << "info3() called" << endl; }
void info4(Copier_Fax &) { cout << "info4() called" << endl; }

int main()
{
	Copier_Fax cf;							// Copier_Fax object
	info1(cf);								// standard conversion, through vb_ptr
	info2(cf);								// standard conversion, delta Copier
	info3(cf);								// standard conversion, no delta
	info4(cf);								// no conversion

	PtrList<Machine> mlist;				// list of Machine *
	mlist.append(new Copier_Fax);		// Copier_Fax * to Machine *

	for (PtrIterator<Machine> iter(mlist); !iter; iter++) {
		//info4(*iter());					// base to derived, illegal
		//info4(*static_cast<Copier_Fax *>(iter());		// error, cannot cast
		Copier_Fax *cp;
		cp = dynamic_cast<Copier_Fax *>(iter());		// OK
		if (cp) info4(*cp);									// legal and safe
	}
	return 0;
}

/**********************************************************************

$ fax3 
info1() called
info2() called
info3() called
info4() called
info4() called

*/
