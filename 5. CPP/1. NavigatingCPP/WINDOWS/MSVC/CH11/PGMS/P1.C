// p1.C - Public inheritance
#include "Person1.h"

int main()
{
	Person p1("John", "Doe", "867-89-1234");		// initialize Person p1
	Person p2("Jane", "Smith", "934-56-7890");	// initialize Person p2
	Student s1("Joe", "Jones", "823-98-6543", "Chemistry", 3.75);
	p1.output(cout);							// invoke Person::output() for p1
	s1.output(cout);							// invoke Person::output() for s1
	return 0;
}
/*************************************************************************

$ p1
Person constructor for John Doe
Person constructor for Jane Smith
Person constructor for Joe Jones
Student constructor for Joe Jones
Doe, John (867-89-1234)
Jones, Joe (823-98-6543)
Student destructor for Joe Jones
Person destructor for Joe Jones
Person destructor for Jane Smith
Person destructor for John Doe

*/
