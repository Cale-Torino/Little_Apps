// dev3.C - Multiple inclusion, object layout and conversions
#include <iostream.h>
#include "Device.h"
#include "PtrList.h"

void rfunc(ReadDevice &) { cout << "rfunc() called" << endl; }
void dvfunc(Device &) { cout << "dvfunc() called" << endl; }
void dkfunc(Disk &) { cout << "dkfunc() called" << endl; }
void rwfunc(ReadWrite &) { cout << "rwfunc() called" << endl; }

int main()
{
	Disk d1;
	rfunc(d1);									// OK
	//dvfunc(d1);								// error
	dkfunc(d1);									// OK
	rwfunc(d1);									// OK
	return 0;
}

/**********************************************************************

$ dev3 
rfunc() called
dkfunc() called
rwfunc() called

*/
