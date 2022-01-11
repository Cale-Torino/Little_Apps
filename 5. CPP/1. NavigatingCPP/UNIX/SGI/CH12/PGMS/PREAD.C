// pread.C - Restore list of Solid shapes
#include "Solid.h"
#include "PtrList.h"
#include "String.h"

void solid_info(const PtrList<Solid> &);
void read_list(PtrList<Solid> &);

int main()
{
	try {
		 PtrList<Solid> solidlist;
		 read_list(solidlist);					// restore List of Solids
		 solid_info(solidlist);
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

void solid_info(const PtrList<Solid> & list) {
	for (PtrIterator<Solid> iter(list); !iter; iter++) 
	   cout << *iter();						// virtual output
}

void read_list(PtrList<Solid> & list) {
	String ifile = "solid.dat";				// read persistent data
	ifstream from(ifile);
	if (!from) 
		throw PersistError("Can't open input file " + ifile);
	try {
		 do {
		     Persist *pobj = Persist::restore(from);
			  if (pobj) {
					Solid *solidptr = dynamic_cast<Solid *>(pobj);
					if (solidptr)
						 list.append(solidptr);
					else 
						throw PersistError(typeid(*pobj).name() + 
							String(" object not a Solid"));
			  }
		 } while (!from.eof());
	}
	catch (const PersistError & e) {
		e.response();
	}
}

/********************************************************************

$ pread
Cube with side 4
Sphere with radius 2
Cylinder with height 4 and radius 6

*/
