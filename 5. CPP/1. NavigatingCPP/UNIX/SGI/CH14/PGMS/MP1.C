// mp1.C - Writing Persistent Shapes with multiple inheritance 
#include "PShape.h"
#include "PString.h"
#include "PtrList.h"

template <class TYPE> 
void save_list(const PtrList<TYPE> &, const String &);

void build_list(PtrList<Shape> &);
void build_list(PtrList<Persist_String> &);

int main()
{
	try {
		PtrList<Shape> shapelist;
		PtrList<Persist_String> stringlist;
		String file1 = "shape.dat";
		String file2 = "string.dat";

		build_list(shapelist);
		save_list(shapelist, file1);
		build_list(stringlist);
		save_list(stringlist, file2);
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

void build_list(PtrList<Shape> & list) {
	list.append(new Persist_Square(5));
	list.append(new Persist_Circle(3));
	list.append(new Persist_RTriangle(4, 6));
}

void build_list(PtrList<Persist_String> & list) {
	list.append(new Persist_String("harpo"));
	list.append(new Persist_String("groucho"));
	list.append(new Persist_String("chico"));
}

template <class TYPE> 
void save_list(const PtrList<TYPE> & list, const String & fname) {
	ofstream to(fname);
	if (!to) 
		throw PersistError("Can't open output file " + fname);
	for (PtrIterator<TYPE> iter(list); !iter; iter++) {
		Persist *pobj = dynamic_cast<Persist *>(iter());
		if (pobj)
			to << *pobj << endl;					// virtual save
	}
}

/*********************************************************************

$ mp1
(no output, writes shape.dat, string.dat files)

*/
