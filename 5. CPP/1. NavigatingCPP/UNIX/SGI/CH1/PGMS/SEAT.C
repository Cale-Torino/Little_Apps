// seat.c - associations
#include <iostream.h>
#include "List.h"

class Passenger;								// forward reference

class Ticket {
private:
	Passenger *traveler;						// one traveler
	friend ostream & operator<<(ostream & os, const Ticket & ) { return os; }
};

class Passenger {
private:
	List<Ticket> tickets;					// many tickets
};

class Seat {
private:
	Passenger *occupant;						// occupant may be 0
public:
	Seat() { occupant = new Passenger; }
	~Seat() { delete occupant; }
	bool IsOccupied() const { return occupant != 0; }
};

void checkseat(const Seat & myseat) {
	if (myseat.IsOccupied())
		cout << "somebody's sitting there!" << endl;
}

int main() {
	Seat myseat;
	checkseat(myseat);
	return 0;
}

/**************************************************************************

$ seat
somebody's sitting there!

*/
