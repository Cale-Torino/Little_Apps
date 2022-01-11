// p8.C - Using a pointer-based List class
#include "PtrList.h"
#include "Person4.h"

int main()
{
	PtrList<Person> list;
   list.append(new Person("John", "Doe", "867-89-1234"));
	list.append(new Student("Jane", "Smith", "934-56-7890", "Biology", 3.5));
	PtrIterator<Person> iter(list);
	list.append(new Student(*iter(), "linguistics", 4.0));
	list.append(new Person("Joe", "Jones", "823-98-6543"));

	cout << list << endl;

	for (iter.restart(); !iter; iter++) {
	   cout << *iter();
		cout << "*********" << endl;
	}
	return 0;
}
/****************************************************************

$ p8
Doe, John (867-89-1234)
Smith, Jane (934-56-7890)
Biology: 3.5
Doe, John (867-89-1234)
linguistics: 4
Jones, Joe (823-98-6543)
 
Doe, John (867-89-1234)
*********
Smith, Jane (934-56-7890)
Biology: 3.5
*********
Doe, John (867-89-1234)
linguistics: 4
*********
Jones, Joe (823-98-6543)
*********

*/
