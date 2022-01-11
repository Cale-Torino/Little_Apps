// p7.C - polymorphic inheritance
#include "Person4.h"

int main()
{
	int i;
   const int MaxPers = 4;
   Person * pers[MaxPers];   					// array of pointers to Person
   pers[0] = new Person("John", "Doe", "867-89-1234");
	pers[1] = new Student("Jane", "Smith", "934-56-7890", "Biology", 3.5);
	pers[2] = new Student(*pers[0], "linguistics", 4.0);
	pers[3] = new Person("Joe", "Jones", "823-98-6543");

	for (i = 0; i < MaxPers; i++) {
	   cout << *pers[i];                 // virtual call
		cout << "*********" << endl;
	}
	for (i = 0; i < MaxPers; i++) {
	   delete pers[i];                  // virtual call
	}
	return 0;
}

/**************************************************************

$ p7
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
