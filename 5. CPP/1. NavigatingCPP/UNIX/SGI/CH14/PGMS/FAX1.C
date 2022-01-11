// fax1.C - Virtual Bases
#include <iostream.h>
#include "Machine.h"
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
	mlist.append(new Fax);					// Fax * to Machine * conversion
	mlist.append(new Copier);				// Copier * to Machine * conversion
	mlist.append(new Copier_Fax);			// Copier_Fax * to Machine * conversion
}

/**********************************************************************

$ fax1 
Fax power_on()
Fax::execute()
Fax::receive()
Fax::print()

Copier power_on()
Copier::execute()
Copier::copy()
Copier::print()
Copier::collate()

Copier_Fax power_on()
Fax::execute()
Fax::receive()
Fax::print()
Copier::execute()
Copier::copy()
Copier::print()
Copier::collate()

Fax power_off()
Copier power_off()
Copier_Fax power_off()

*/
