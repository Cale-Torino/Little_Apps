// mp2.C - Reading Persistent Shapes with multiple inheritance 
#include "PShape.h"
#include "PString.h"
#include "PtrList.h"

template <class TYPE> 
void list_info(const PtrList<TYPE> & list);

template <class TYPE> 
void read_list(PtrList<TYPE> & list, const String & fname);

int main()
{
	try {
		PtrList<Shape> shapelist;
		PtrList<String> stringlist;
		String file1 = "shape.dat";
		String file2 = "string.dat";

		read_list(shapelist, file1);
		list_info(shapelist);

		read_list(stringlist, file2);
		list_info(stringlist);
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

template <class TYPE> 
void list_info(const PtrList<TYPE> & list) {
	for (PtrIterator<TYPE> iter(list); !iter; iter++) {
	   cout << *iter() << endl;				// virtual output
	}
}

template <class TYPE> 
void read_list(PtrList<TYPE> & list, const String & fname) {
	ifstream from(fname);
	if (!from) 
		throw PersistError("Can't open input file " + fname);
	try {
		 do {
		     Persist *pobj = Persist::restore(from);
			  if (pobj) {
					TYPE *objectptr = dynamic_cast<TYPE *>(pobj);
					if (objectptr)
						 list.append(objectptr);
					else 
						throw PersistError(typeid(*pobj).name() + 
							String(" Bad object type"));
			  }
		 } while (!from.eof());
	}
	catch (const PersistError & e) {
		e.response();
	}
}

/*********************************************************************

$ mp2
class Persist_Square: side 5
class Persist_Circle: radius 3
class Persist_RTriangle: height 4, base 6
harpo
groucho
chico

*/
