// taxes.c - class names, qualification
#include <iostream.h>
#include "Assoc.h"
#include "String.h"

class Person {
private:
	String soc_sec_num;							// social security number
};

class IRS {
private:
	Assoc<String, Person *> taxpayer;		// map String to Person *
};

int main()
{
	return 0;
}
