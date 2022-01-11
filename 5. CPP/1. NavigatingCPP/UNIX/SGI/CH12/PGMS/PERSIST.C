// persist.c - persistent implementation
#include "Persist.h"
#include "Solid.h"

int Solid::count = 0;

const int MaxClasses = 10;
Assoc<String, Persist::PTRF> Persist::typemap(MaxClasses);

void Persist::do_mapping() {
	try {
		 typemap[typeid(Sphere).name()] = Sphere::new_sphere;
		 typemap[typeid(Cube).name()] = Cube::new_cube;
		 typemap[typeid(Cylinder).name()] = Cylinder::new_cylinder;
	}
	catch (const AssocError<String, PTRF> & err) {
		err.response();
	  	throw PersistError("Cannot create mappings");
	}
}

Persist *Persist::restore(ifstream & ifs) {
	static bool Is_mapped = true;
	if (Is_mapped == true) {
  		do_mapping();
		Is_mapped = false;
	}
	String whattype;
	Persist *pobj = 0;
	ifs >> whattype;							// input type
	if (ifs) {
		 try {
			  PTRF create_object = typemap[whattype];
			  pobj = create_object(ifs);
		 }
		 catch (const AssocError<String, PTRF> & err) {
		 	err.response();
			throw PersistError("Can't find class type");
		 }
	}
	return pobj;
}
