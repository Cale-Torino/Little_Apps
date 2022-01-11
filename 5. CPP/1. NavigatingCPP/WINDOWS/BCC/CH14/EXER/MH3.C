// mh3.C - Distinct Bases, Object layout and conversions
#include <iostream.h>
#include "Motorhm1.h"
#include "PtrList.h"

void vfunc(Vehicle &) { cout << "vfunc() called" << endl; }
void rfunc(Residence &) { cout << "rfunc() called" << endl; }
void mfunc(MotorHome &) { cout << "mfunc() called" << endl; }
void lfunc(LandVehicle &) { cout << "lfunc() called" << endl; }

int main()
{
	MotorHome mh(30, 120);			// create MotorHome
	vfunc(mh);							// MotorHome & to Vehicle & conversion
	rfunc(mh);							// MotorHome & to Residence & conversion
	mfunc(mh);							// no conversion
	lfunc(mh);							// MotorHome & to LandVehicle & conversion
	return 0;
}

/**********************************************************************

$ mh3 
vfunc() called
rfunc() called
mfunc() called
lfunc() called

NOTES:
	1. In Figure 14.4, the LandVehicle base address is the same base address
		as Vehicle and MotorHome.

	2. The conversion of MotorHome & to LandVehicle & in lfunc() requires 
		NO computation, since their base addresses are the same.

*/
