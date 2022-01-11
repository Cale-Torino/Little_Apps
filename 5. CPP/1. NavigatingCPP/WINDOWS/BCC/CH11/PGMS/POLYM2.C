// polym2.C - polymorphic inheritance with List container
#include <iostream.h>
#include "PtrList.h"
#include "Person4.h"

void run(const PtrList<Person> & list) {
	for (PtrIterator<Person> iter(list); !iter; iter++)
		cout << *iter() << endl;					// virtual call
}

int main()
{
	try {
		 PtrList<Person> list;
		 list.append(new Person("John", "Doe", "867-89-1234"));
		 list.append(new Student("Jane", "Smith", "934-56-7890", 
			 "Biology", 3.5));
		 PtrIterator<Person> iter(list);
		 list.append(new Student(*iter(), "Linguistics", 4.0));
		 list.append(new Person("Joe", "Jones", "823-98-6543"));

		 run(list);									// execute virtual calls
	}
	catch (const ListError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*********************************************************************

$ polym2
Doe, John (867-89-1234)

Smith, Jane (934-56-7890)
Biology: 3.5

Doe, John (867-89-1234)
Linguistics: 4

Jones, Joe (823-98-6543)

*/
