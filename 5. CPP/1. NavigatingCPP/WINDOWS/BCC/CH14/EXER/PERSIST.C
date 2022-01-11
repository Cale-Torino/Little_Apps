// persist.c - persistent implementation
#include <iostream.h>
#include "Persist.h"
#include "PShape.h"
#include "PString.h"

const int MaxClasses = 10;
Assoc<String, Persist::PTRF> Persist::typemap(MaxClasses);

int Shape::count = 0;

void Persist::do_mapping() {
	try {
		typemap[typeid(Persist_Circle).name()] = 
					Persist_Circle::new_circle;
		typemap[typeid(Persist_Square).name()] = 
					Persist_Square::new_square;
		typemap[typeid(Persist_RTriangle).name()] = 
					Persist_RTriangle::new_triangle;
		typemap[typeid(Persist_String).name()] = 
					Persist_String::new_string;
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
