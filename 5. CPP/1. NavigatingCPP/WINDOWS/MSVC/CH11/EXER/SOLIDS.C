// solids.C - PtrList class with Solids
#include <iostream.h>
#include "PtrList.h"
#include "Solid.h"

void build_list(PtrList<Solid> &);
void solid_info(const PtrList<Solid> &);

int main() 
{
	try {
		 PtrList<Solid> solidlist;

		 build_list(solidlist);							// build a Solid list
		 solid_info(solidlist);							// display Solid data

		 PtrIterator<Solid> iter(solidlist);
		 delete solidlist.remove(iter);				// remove first Solid
		 cout << "There are " << Solid::num_solids() 
				 << " solids left" << endl;
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

void build_list(PtrList<Solid> & list) {
	list.append(new Cube(4));
	list.append(new Sphere(2));
	list.append(new Cylinder(4, 6));
	cout << "Solid list built with " << 
			Solid::num_solids() << " solids" << endl;
}

void solid_info(const PtrList<Solid> & list) {
	for (PtrIterator<Solid> iter(list); !iter; iter++) {
		cout << "I'm a " << *iter() << ", ";
		cout << "surface area " << iter()->surface_area() << " and ";
		cout << "volume " << iter()->volume() << endl;
	}
}

/**********************************************************************

$ solids
Solid list built with 3 solids
I'm a Cube: side 4, surface area 96 and volume 64
I'm a Sphere: radius 2, surface area 50.2655 and volume 33.5103
I'm a Cylinder: height 4, radius 6, surface area 376.991 and volume 452.389
There are 2 solids left

*/
