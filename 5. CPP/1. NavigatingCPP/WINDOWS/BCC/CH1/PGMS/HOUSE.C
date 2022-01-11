// house.c - class descriptions, aggregation

class Stove { } ;

class Kitchen {
private:
	Stove cooker;						// Stove is inside Kitchen
};

class House {
private:
	Kitchen cookingplace;			// Kitchen is inside House
public:
	void sell() { }
};

int main()
{
	House h;
	h.sell();
	return 0;
}
