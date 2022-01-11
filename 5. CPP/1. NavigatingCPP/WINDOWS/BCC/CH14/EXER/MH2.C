// mh2.C - resolving ambiguities
#include <iostream.h>
#include "Motorhm1.h"
#include "PtrList.h"

int main()
{
	House h(3000);								// create House
	cout << "House" << endl;
	h.output(cout);							// House::output(); no ambiguity
	cout << endl;

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

$ mh2 
House
square footage = 3000

Vehicles
length = 18
length = 75
length = 100

NOTES:
	1. House is derived from Residence.
		MotorCycle is derived from LandVehicle.
		AirPlane is derived from AirVehicle, a new class that we derive
		from Vehicle.

	2. In classes WaterVehicle, LandVehicle, and AirVehicle, we use virtual
		public to make Vehicle a shared base class.

	3. In the constructors for classes Boat, MotorCycle, and AirPlane we MUST 
		initialize Vehicle(len), since virtual base Vehicle does NOT have 
		default arguments. Note that these classes are NOT multiply-derived,
		but they all are subclasses of base classes that have virtual bases.

	4. SeaPlane is multiply-derived from AirPlane and WaterVehicle.
		Since both of these bases derive from Vehicle and we do NOT want more
		than one Vehicle in SeaPlane, we use virtual bases (Pattern 3).
		The SeaPlane constructor must initialize virtual base Vehicle
		with Vehicle(len).

	5. In SeaPlane, we must override go() and stop(). Otherwise, the compiler
		reports amibiguities, since there are versions of go() and stop() in
		both WaterVehicle and AirVehicle (AirPlane is derived from AirVehicle).

	6. Note that SeaPlane suffers from dynamic classification, since it cannot
		be a WaterVehicle when it is flying or be an AirVehicle when it's on
		the water.

*/
