// p5.C - Base and derived class standard conversions with references
#include "Person2.h"

int main()
{
	Person p1("John", "Doe", "867-89-1234");
	Student s2("Jane", "Smith", "934-56-7890", "Biology", 3.5);

	Person & rp1 = p1;				// no conversion
	rp1.output(cout);					// calls Person::output()

	Person & rp2 = s2;				// OK (derive to base) 
	rp2.output(cout);					// calls Person::output()
	static_cast<Student &>(rp2).output(cout);		// Student::output()

	// Student & rs1 = p1;			// illegal (base to derive)
	Student & rs1 = static_cast<Student &>(p1);			// unsafe
	cout << rs1.get_gpa() << endl;							// garbage
	return 0;
}

/********************************************************************

$ p5
Doe, John (867-89-1234)
Smith, Jane (934-56-7890)
Smith, Jane (934-56-7890)
Biology: 3.5
1.54484e-308

*/
