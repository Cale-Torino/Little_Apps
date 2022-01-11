// money.C - enumerated types
#include <iostream.h>

enum coins { penny = 1, nickel = 5, dime = 10, qtr = 25, half = 50 };
enum bills { dollar = 1, five = 5, ten = 10, twenty = 20, fifty = 50 };

const int max = 5;

struct money {										// money definition
	coins coin[max];
	bills bill[max];
};

int main()
{
	void count(const money &);

	static money bag = {							// fill the bag with money
		{ dime, qtr, nickel, penny, nickel },
		{ fifty, ten, five, dollar, dollar}
	};

	count(bag);										// count the money
	return 0;
}

void count(const money & loot) {
	int paper = 0, silver = 0;
	
	for (int i = 0; i < max; i++) {
	 	paper += loot.bill[i];
	 	silver += loot.coin[i];
	}
	cout << "You've got " << paper << " dollars ";
	cout << "and " << silver << " cents." << endl;
}

/*******************************************************************

$ money
You've got 67 dollars and 46 cents.

*/
