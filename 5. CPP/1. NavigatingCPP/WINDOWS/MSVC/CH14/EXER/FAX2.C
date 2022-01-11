// fax2.C - Virtual Bases, base class initializers
#include <iostream.h>
#include "Machine4.h"
#include "PtrList.h"

void build_list(PtrList<Machine> &);
void list_info(const PtrList<Machine> &);

int main()
{
	PtrList<Machine> mlist;					// list of Machine *
	build_list(mlist);
	list_info(mlist);
	return 0;
}

void list_info(const PtrList<Machine> & mlist) {
	PtrIterator<Machine> iter(mlist);	// setup Iterator
	for (; !iter; iter++) {
		iter()->power_on();
		iter()->execute();					// "execute" machine
		cout << endl;
	}
	for (iter.restart(); !iter; iter++)
		iter()->power_off();
}

void build_list(PtrList<Machine> & mlist) {
	mlist.append(new Fax(72));					// Fax with serial number 72
	mlist.append(new Copier(82));				// Copier with serial number 82
	mlist.append(new Copier_Fax(92));		// Copier_Fax with serial number 92
}

/**********************************************************************

$ fax2 
class Fax 72: power_on()
Fax::execute()
Fax::receive()
Fax::print()

class Copier 82: power_on()
Copier::execute()
Copier::copy()
Copier::print()
Copier::collate()

class Copier_Fax 92: power_on()
Fax::execute()
Fax::receive()
Fax::print()
Copier::execute()
Copier::copy()
Copier::print()
Copier::collate()

class Fax 72: power_off()
class Copier 82: power_off()
class Copier_Fax 92: power_off()

NOTES:
	1. In this version, we default the serial numbers in the Fax and Copier constructors
		to zero. There is no default for the serial number in the Machine constructor,
		however.

	2. With this approach, the Copier_Fax constructor does NOT have to explicitly
		initialize the Fax and Copier classes in its member initialization list.
		All that is required is an initializtion of the Machine class with a serial
		number.

*/
