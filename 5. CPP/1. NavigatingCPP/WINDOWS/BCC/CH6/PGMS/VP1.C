// vp1.C - void pointers
#include <iostream.h>

void f(void *) { cout << "void *" << endl; }
void h(const void *) { cout << "const void *" << endl; }
void j(volatile void *) { cout << "volatile void *" << endl; }
void k(const volatile void *) { cout << "const volatile void *" << endl; }

int main() {
	 const int b = 12;
	 const int *r = &b;
	 //f(r);

	 volatile int c = 12;
	 volatile int *w = &c;
	 //f(w);

	 const volatile int d = 12;
	 const volatile int *v = &d;
	 //f(v);

	 struct block {
	 	int num;
		char a[80];
	 } x = { 12, "abc" };
	 cout << x.num << endl;

	 const block e = { 1, "one" };
	 const block *m = &e;
	 //f(m);

	 union jack {
		char a[4];
	 	long num;
	 } z = { "abc" };
	 cout << z.a << endl;

	 const jack g = { "two" };
	 const jack *n = &g;
	 //f(n);

	 h(r);
	 h(m);
	 h(n);
	 j(w);
	 k(v);

	 cout << (void *)r << ' ' << (void *)w << ' ' 
	 		<< (void *)v << ' ' << (void *)m << ' ' << (void *)n << endl;
	 return 0;
}

/**********************************************************************

$ vp1 
12
abc
const void *
const void *
const void *
volatile void *
const volatile void *
0x7fff2ea0 0x7fff2ea4 0x7fff2ea8 0x7fff2eb0 0x7fff2f10

*/
