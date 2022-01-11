// fastm.c - fast memory
#include <iostream.h>
#include <assert.h>
#include <malloc.h>

enum Memory { slow, fast };

void *xmalloc(size_t size) {
	void *mp = reinterpret_cast<void *>(0x8888);
	cout << "xmalloc called for " << size << " bytes" << endl;
	cout << "\taddress = " << mp << endl;
	return mp = malloc(size);			// fake the address
}

void xfree(void *mp) {
	cout << "xfree called for " << mp << endl;
}

void *operator new(size_t size, Memory mtype) {
	if (mtype == fast)
		return xmalloc(size);					// allocate from fast memory
	else {
		assert(mtype == slow);					// verify slow request
		cout << "malloc called for " << size << " bytes" << endl;
		void *mp = malloc(size);				// allocate from slow memory
		cout << "\taddress = " << mp << endl;
		return mp;
	}
}

void operator delete(void *mp) {
	static const void *addr = 
		reinterpret_cast<void *>(0x8000);			// start of fast memory		
	if (mp == 0)											// check for zero address
		return;												// do nothing
	if (mp >= addr)										// fast memory address?
		xfree(mp);											// free fast memory
	else {													// slow memory address
		cout << "free called for " << mp << endl;
		free(mp);											// free slow memory
	}
}

class A {
private:
	int num;
public:
	A(int n = 1) : num(n) { cout << "A constr" << endl; }
	~A() { cout << "A destr" << endl; }
};

int main()
{
	A *p = new (slow)  A;					// place object A in slow memory
	A *q = new (fast) A;						// place object A in fast memory
	delete p;									// destory A in slow memory
	delete q;									// destory A in fast memory
	return 0;
}

/**********************************************************************

$ fastm 
malloc called for 4 bytes
	address = 0x10013538
A constr
xmalloc called for 4 bytes
	address = 0x8888
A constr
A destr
xfree called for 0x10013538
A destr
xfree called for 0x10013548

*/
