#ifndef ROMANH
#define ROMANH
// Roman4.h - Roman class interface, static members and functions
#include <iostream.h>

const int Roman_max = 20;

class Roman {
private:
	int value;										// decimal value
	char s[Roman_max];							// Roman String
	void convert_Roman(); 						// convert to Roman string
	static int count;								// static data member
public:
// Constructors
	Roman() { 
		count++; value = count; convert_Roman();
		cout << "Constructor " << count << " for " << 
				value << " (" << getroman() << ')' << endl;
	}
	Roman(const Roman & r1) { 
		count++; value = r1.value; convert_Roman();
		cout << "Constructor " << count << " for " << 
				value << " (" << getroman() << ')' << endl;
	}
// Destructor
	~Roman() { 
		cout << "Destructor " << count << " for " << 
				value << " (" << getroman() << ')' << endl;
		count--;
	}
// Member Functions
	const char *getroman() const { return s; }
	int getnum() const { return value; }
	static int getcount() { return count; }	// static member function
};
#endif
