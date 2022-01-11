// menu.c - Menu objects
#include <iostream.h>
#include "String.h"

class MenuItem {
private:
	String description;
	char command;
	void (*pfunction)();						// pointer to function
public:
	MenuItem(const String & d, char c, void (*pf)()) :
			description(d), command(c), pfunction(pf) { }
	String getdescription() const { return description; }
	char getcommand() const { return command; }
};

void list() { }
void calc() { }

int main()
{
	MenuItem m1("List", 'l', list);							// List item
	MenuItem m2("Caclulate", 'c', calc);					// Calculate item
	cout << m1.getdescription() << ' ' << m1.getcommand() << endl;
	cout << m2.getdescription() << ' ' << m2.getcommand() << endl;
	return 0;
}

/**********************************************************************

$ menu
List l
Caclulate c

NOTES:
1.  According to our boilerplate approach, if a class has a data 
	 member pointer AND its constructor and destructor allocate 
	 and deallocate resources, that class is a strong candidate for 
	 the full boilerplate.

2.  With class MenuItem, however, the pointer points to a function that
	 is shared between MenuItem objects. Furthermore, the MenuItem
	 constructor does not allocate any resources.  Class MenuItem,
	 therefore, does NOT require the full boilerplate.

*/
