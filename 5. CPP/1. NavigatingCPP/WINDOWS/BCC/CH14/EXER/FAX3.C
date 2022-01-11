// fax3.C - Virtual Bases, object layout and conversions
#include <iostream.h>
#include "Machine.h"
#include "PtrList.h"

void info1(Machine &) { cout << "Machine()" << endl; }
void info2(LaserPrinter &) { cout << "LaserPrinter" << endl; }
void info3(Fax &) { cout << "Fax" << endl; }
void info4(Printer_Fax &) { cout << "Printer_Fax" << endl; }

int main()
{
	Printer_Fax cf;						// Printer_Fax object
	info1(cf);								// standard conversion, through vb_ptr
	info2(cf);								// standard conversion, delta LaserPrinter
	info3(cf);								// standard conversion, no delta
	info4(cf);								// no conversion

	PtrList<Machine> mlist;				// list of Machine *
	mlist.append(new Printer_Fax);	// Printer_Fax * to Machine *

	for (PtrIterator<Machine> iter(mlist); !iter; iter++) {
		Printer_Fax *cp;
		cp = dynamic_cast<Printer_Fax *>(iter());		// OK
		if (cp) info4(*cp);									// legal and safe
	}
	return 0;
}

/**********************************************************************

$ fax3 
Machine()
LaserPrinter
Fax
Printer_Fax
Printer_Fax

*/
