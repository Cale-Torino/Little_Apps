// fax4.C - Virtual Bases, base class initializers
#include <iostream.h>
#include "Machine3.h"
#include "PtrList.h"

class Special_Fax : public Fax {
public:
	Special_Fax(long sn) : Machine(sn), Fax(sn) { }
	void execute() { cout << "Special_Fax" << endl; }
};

int main()
{
	PtrList<Machine> mlist;						// list of Machine *
	mlist.append(new Fax(72));					// create Fax
	mlist.append(new Special_Fax(202));		// create Special_Fax

	PtrIterator<Machine> iter(mlist);		// setup Iterator
	for (; !iter; iter++) {
		iter()->power_on();
		iter()->execute();						// "execute" machine
		cout << endl;
	}
	for (iter.restart(); !iter; iter++)
		iter()->power_off();
	return 0;
}

/**********************************************************************

$ fax4 
class Fax 72: power_on()
Fax::execute()
Fax::receive()
Fax::print()

class Special_Fax 202: power_on()
Special_Fax

class Fax 72: power_off()
class Special_Fax 202: power_off()

*/
