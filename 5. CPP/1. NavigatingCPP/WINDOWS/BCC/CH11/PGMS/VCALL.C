// vcall.c - virtual calls in constructors and destructors
#include <iostream.h>

class Base { 
private:
	virtual void init() { cout << "Base:init()" << endl; }
	virtual void cleanup() { cout << "Base:cleanup()" << endl; }
public:
	Base() { init(); }						// calls Base::init()
	virtual ~Base() { cleanup(); }		// calls Base::cleanup()
	void restart() { 
		cleanup();								// virtual call
		init();									// virtual call
	}
};

class Derived: public Base { 
private:
	void init() { cout << "Derived:init()" << endl; }
	void cleanup() { cout << "Derived:cleanup()" << endl; }
public:
	Derived() { init(); }					// calls Derived::init();
	~Derived() { cleanup(); }				// calls Derived::cleanup()
};

int main()
{
	cout << "create Base" << endl;
	Base b;
	b.restart();
	cout << "end of Base" << endl;

	cout << "create Derived" << endl;
	Derived d;
	d.restart();
	cout << "end of Derived" << endl;
	return 0;
}

/**********************************************************************

$ vcall
create Base
Base:init()
Base:cleanup()
Base:init()
end of Base
create Derived
Base:init()
Derived:init()
Derived:cleanup()
Derived:init()
end of Derived
Derived:cleanup()
Base:cleanup()
Base:cleanup()

*/
