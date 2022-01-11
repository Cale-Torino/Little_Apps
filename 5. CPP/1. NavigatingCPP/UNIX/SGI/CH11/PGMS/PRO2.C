// pro2.C - Protected access level, access restrictions
#include <iostream.h>

class B1 {
protected:
	void calc() const;
public:
	void f() const;
};

class D1 : public B1 {
public:
	void w(const B1 & b, const D1 & d) const {
		//b.calc();					// illegal with B1
		d.calc();					// legal with D1
	}
};

class D2 : public D1 {
	friend void z(const B1 &, const D1 &, const D2 &);
	friend class C;
};

void z(const B1 & b, const D1 & d1, const D2 & d2) {
	//b.calc();						// illegal with B1
	//d1.calc();					// illegal with D1
	d2.calc();						// legal with D2
	b.f();							// legal with B1
	d1.w(b, d1);					// legal with D1
}

class C { 
private:
	void f(const B1 & b, const D1 & d1, const D2 & d2) {
		//b.calc();						// illegal with B1
		//d1.calc();					// illegal with D1
		d2.calc();						// legal with D2
	}
	void g(const B1 & b, const D1 & d1, const D2 & d2) {
		//b.calc();						// illegal with B1
		//d1.calc();					// illegal with D1
		d2.calc();						// legal with D2
	}
};
