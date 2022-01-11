// dev2.C - Multiple inclusion, resolving amibiguites
#include <iostream.h>
#include "Device.h"
#include "PtrList.h"

void dvfunc(Device *) { cout << "dvfunc() called" << endl; }

int main()
{
	PtrList<ReadDevice> rlist;
	rlist.append(new CDROM);
	rlist.append(new Disk);
	for (PtrIterator<ReadDevice> r_iter(rlist); !r_iter; r_iter++)
		r_iter()->reset();					// no ambiguity

	Disk *dp1 = new Disk;
	//dp1->reset();							// error, which reset()?
	//dvfunc(dp1);								// error, ambiguous, which Device *?

	ReadDevice *rp = dynamic_cast<ReadDevice *>(dp1);
	if (rp) dvfunc(rp);						// OK

	Disk a;										// create Disk object
	//Device *dptr = dynamic_cast<Device *>(&a);			// compiles OK
	//if(dptr) {									// dynamic cast successful
		//cout << "never executes" << endl;
	//} else {										// dynamic cast fails
		//cout << "always executes" << endl;
	//}
	return 0;
}

/**********************************************************************

$ dev2 
dvfunc() called

*/
