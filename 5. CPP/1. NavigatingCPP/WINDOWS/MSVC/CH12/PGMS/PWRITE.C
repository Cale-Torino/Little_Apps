// pwrite.C - Write Persistent Solids
#include "Solid.h"
#include "PtrList.h"
#include "String.h"

void build_list(PtrList<Solid> &);
void save_list(const PtrList<Solid> &);

int main()
{
	try {
		 PtrList<Solid> solidlist;
		 build_list(solidlist);					// create List of Solids
		 save_list(solidlist);					// save List
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	catch (const PersistError & e) {
		e.response();
		return 1;
	}
	return 0;
}

void build_list(PtrList<Solid> & list) {
    list.append(new Cube(4));
    list.append(new Sphere(2));
    list.append(new Cylinder(4, 6));
}

void save_list(const PtrList<Solid> & list) {
	String ofile = "solid.dat";				// store peristent data
	ofstream to(ofile);
	if (!to) 
		throw PersistError("Can't open output file " + ofile);
	for (PtrIterator<Solid> iter(list); !iter; iter++) 
	   to << *iter() << endl;						// virtual save
}

/**********************************************************************

$ pwrite 
(no output, writes to solid.dat file)

*/
