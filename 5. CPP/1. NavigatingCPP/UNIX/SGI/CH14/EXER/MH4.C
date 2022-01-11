// mh4.C - resolving ambiguities with operator<<()
#include <iostream.h>
#include "Motorhm2.h"
#include "PtrList.h"

int main()
{
	House h(3000);								// create House
	cout << "House" << endl;
	h.output(cout);							// House::output(); no ambiguity
	cout << endl;

	MotorHome mh(30, 120);					// create MotorHome
	cout << "MotorHome" << endl;
	cout << mh << endl;						// no ambiguity

	HouseBoat hb("Westwind", 40, 450);	// create HouseBoat
	cout << "HouseBoat" << endl;
	cout << hb << endl;						// no ambiguity

	PtrList<Vehicle> vlist;					// list of Vehicle *
	cout << "Vehicles" << endl;
	vlist.append(new MotorCycle(18));
	vlist.append(new AirPlane(75));
	vlist.append(new SeaPlane(100));
	for (PtrIterator<Vehicle> iter(vlist); !iter; iter++)
		cout << *iter();						// no ambiguity

	Vehicle *vp = dynamic_cast<Vehicle *>(&h);
	if (vp) 
		cout << *vp << endl;
	return 0;
}

/**********************************************************************

$ mh4 
House
square footage = 3000

MotorHome
length = 30
square footage = 120

HouseBoat
length = 40
name = Westwind
square footage = 450

Vehicles
length = 18
length = 75
length = 100

*/
