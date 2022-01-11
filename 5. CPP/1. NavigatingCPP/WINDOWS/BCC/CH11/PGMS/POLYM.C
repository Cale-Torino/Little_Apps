// polym.C - polymorphic inheritance with Array container
#include <iostream.h>
#include "Array.h"
#include "Person4.h"

void run(const Array<Person *> & a) {
	for (int i = 0; i < a.length(); i++)
		cout << *a[i] << endl;					// virtual call
}

int main()
{
	try {
		 const int MaxPers = 4;
		 Array<Person *> pers(MaxPers);				// Person pointer array
		 pers[0] = new Person("John", "Doe", "867-89-1234");
		 pers[1] = new Student("Jane", "Smith", 
		 					"934-56-7890", "Biology", 3.5);
		 pers[2] = new Student(*pers[0], "Linguistics", 4.0);
		 pers[3] = new Person("Joe", "Jones", "823-98-6543");

		 run(pers);									// execute virtual calls
		 for (int i = 0; i < MaxPers; i++)
			 delete pers[i];						// virtual call
	}
	catch (const ArrayError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/*********************************************************************

$ polym
Doe, John (867-89-1234)

Smith, Jane (934-56-7890)
Biology: 3.5

Doe, John (867-89-1234)
Linguistics: 4

Jones, Joe (823-98-6543)

*/
