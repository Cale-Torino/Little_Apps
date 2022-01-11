// customer.c - class descriptions, associations

class Automobile;				// forward reference

class Customer {
private:
	Automobile *mycar;		// points to an Automobile object
public:
	void buy() { }
};

class Automobile {
private:
	Customer *owner;			// points to a Customer object
};

int main()
{
	Customer c;
	c.buy();
	return 0;
}
