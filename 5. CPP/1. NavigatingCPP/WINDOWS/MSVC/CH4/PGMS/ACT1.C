// act1.C - member initialization
#include <iostream.h>
#include <string.h>
#include "Roman.h"
#include "Fifo5.h"

class Act {
private:
	char title[80];								// character array
	Roman r;											// containment of Roman object
	Fifo f;											// containment of Fifo object
public:
	Act(const char *t, int num, int len) : r(num), f(len) {
		strcpy(title, t);
	}
	const char *getact() const { return r.getroman(); }
};

class Node {
private:
	Node *pf;										// pointer to another Node
	int data;										// integer data
public:
	Node(int d) : pf(0), data(d) { }
	int getdata() const { return data; }
};

int main()
{
	try {
		Act play("theater", 1, 32056);
		cout << "Act " << play.getact() << endl;
		Node n(101);
		cout << n.getdata() << endl;
	}
	catch (const FifoError & e) {
		e.response();
		return 1;
	}
	return 0;
}

/**********************************************************************

$ act1 
Act I
101

*/
