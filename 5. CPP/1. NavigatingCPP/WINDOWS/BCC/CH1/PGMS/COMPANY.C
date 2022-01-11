// company.c - class names, link attributes, roles
#include <iostream.h>
#include "Array.h"
#include "String.h"

class Person;									// forward reference
class Company;									// forward reference

class Position {
private:
	Person *employee;
	Company *employer;
	long salary;
	String job_title;
};

class Person {
private:
	// a Person may have more than one "position"
	Array<Position *> employers;			// template container class
};

class Company {
private:
	// a Company may have more than one "position"
	Array<Position *> employees;			// template container class
};

int main()
{
	Company c;
	return 0;
}
