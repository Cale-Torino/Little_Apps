// mh1.C - Using a distinct bases multiple inheritance polymorphically
#include <iostream.h>
#include "Motorhme.h"
#include "PtrList.h"

void build_list(PtrList<Vehicle> &);
void build_list(PtrList<Residence> &);
void list_info(const PtrList<Vehicle> &);
void list_info(const PtrList<Residence> &);

int main()
{
	PtrList<Vehicle> vlist;							// list of Vehicle *
	PtrList<Residence> rlist;

	build_list(vlist);
	build_list(rlist);

	list_info(vlist);
	list_info(rlist);
	return 0;
}

void list_info(const PtrList<Residence> & list) {
	for (PtrIterator<Residence> iter(list); !iter; iter++) {
		cout << *iter();
		iter()->move_in();
		iter()->move_out();
		Vehicle *vp = dynamic_cast<Vehicle *>(iter());
		if (vp) {
			vp->stop();									// OK
			vp->go();									// OK
		}
		cout << endl;
	}
}

void list_info(const PtrList<Vehicle> & list) {
	for (PtrIterator<Vehicle> iter(list); !iter; iter++) {
		cout << *iter();
		iter()->go();
		iter()->stop();
		Residence *rp = dynamic_cast<Residence *>(iter());
		if (rp) {
			rp->move_in();								// OK
			rp->move_out();							// OK
		}
		cout << endl;
	}
}

void build_list(PtrList<Residence> & list) {
	list.append(new MotorHome(30, 120));
	list.append(new HouseBoat("WestWind", 40, 800));
}

void build_list(PtrList<Vehicle> & list) {
	list.append(new MotorHome(12, 96));
	list.append(new HouseBoat("WestWind", 40, 800));
	list.append(new Boat("Mary Jane", 19));
}

/**********************************************************************

$ mh1 
length = 12
square footage = 96
LandVehicle::go()
LandVehicle::stop()
Motorhome::move_in()
Motorhome::move_out()

length = 40
name = WestWind
square footage = 800
WaterVehicle::go()
WaterVehicle::stop()
HouseBoat::move_in()
HouseBoat::move_out()

length = 19
name = Mary Jane
WaterVehicle::go()
WaterVehicle::stop()

length = 30
square footage = 120
Motorhome::move_in()
Motorhome::move_out()
LandVehicle::stop()
LandVehicle::go()

length = 40
name = WestWind
square footage = 800
HouseBoat::move_in()
HouseBoat::move_out()
WaterVehicle::stop()
WaterVehicle::go()

*/
