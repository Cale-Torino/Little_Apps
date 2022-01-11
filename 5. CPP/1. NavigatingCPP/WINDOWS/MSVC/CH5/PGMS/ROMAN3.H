#ifndef ROMANH
#define ROMANH
// Roman3.h - Roman class interface
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
	Roman(int n = 1) { 
		count++; value = n; convert_Roman();
		cout << "Constructor for " << value << " (" 
				<< getroman() << ')' << endl;
	}
	Roman(const Roman & r1) { 
		count++; value = r1.value; convert_Roman();
		cout << "Constructor for " << value << " (" 
				<< getroman() << ')' << endl;
	}
// Destructor
	~Roman() { 
		cout << "Destructor for " << value << " (" 
				<< getroman() << ')' << endl;
		count--; 
	}
// Member Functions
	const char *getroman() const { return s; }
	int getnum() const { return value; }
	static int getcount() { return count; }			// static member function
};
#endif
