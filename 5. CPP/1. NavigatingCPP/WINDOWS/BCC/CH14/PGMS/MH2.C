// mh2.C - resolving ambiguities
#include <iostream.h>
#include "Motorhme.h"
#include "PtrList.h"

int main()
{
	MotorHome mh(30, 120);					// create MotorHome
	cout << "MotorHome" << endl;
	mh.output(cout);							// MotorHome::output(); no ambiguity

	PtrList<Vehicle> vlist;					// list of Vehicle *
	cout << "Vehicles" << endl;
	vlist.append(new MotorHome(30, 120));
	vlist.append(new HouseBoat("WestWind", 40, 450));
	for (PtrIterator<Vehicle> iter(vlist); !iter; iter++)
		cout << *iter();						// no ambiguity

	Vehicle *vp = dynamic_cast<Vehicle *>(&mh);
	if (vp) cout << *vp << endl;
	return 0;
}

/**********************************************************************

$ mh2 
MotorHome
length = 30
square footage = 120
Vehicles
length = 30
square footage = 120
length = 40
name = WestWind
square footage = 450
length = 30
square footage = 120

*/
