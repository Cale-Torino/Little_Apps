// mh3.C - Distinct Bases, Object layout and conversions
#include <iostream.h>
#include "Motorhme.h"
#include "PtrList.h"

void vfunc(Vehicle &) { cout << "vfunc() called" << endl; }
void rfunc(Residence &) { cout << "rfunc() called" << endl; }
void mfunc(MotorHome &) { cout << "mfunc() called" << endl; }

int main()
{
	MotorHome mh(30, 120);			// create MotorHome
	vfunc(mh);							// MotorHome & to Vehicle & conversion
	rfunc(mh);							// MotorHome & to Residence & conversion
	mfunc(mh);							// no conversion
	return 0;
}

/**********************************************************************

$ mh3 
vfunc() called
rfunc() called
mfunc() called

*/
