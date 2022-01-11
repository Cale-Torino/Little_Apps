// p4.C - Base and derived class standard conversions with pointers
#include "Person2.h"

int main()
{
	Person p1("John", "Doe", "867-89-1234");  
	Student s2("Jane", "Smith", "934-56-7890", "Biology", 3.5);  

	Person *pptr2 = &s2;							// standard conversion
	// cout << pptr2->get_gpa() << endl;	// illegal, no Person::get_gpa()
	cout << static_cast<Student *>(pptr2)->get_gpa() << endl; 	// OK

	// Student *sptr1 = &p1;									// illegal
	Student *sptr1 = static_cast<Student *>(&p1);		// unsafe
	cout << sptr1->get_gpa() << endl;						// garbage
	return 0;
}

/*********************************************************************

$ p4
3.5
1.54477e-308

*/
