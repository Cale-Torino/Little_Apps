// vf4.C - virtual functions
#include "Base4.h"

int main()
{
  void func(B&);
  B b1;
  D d1;
  func(b1);
  cout << "******************" << endl;
  func(d1);
  return 0;
}

void func(B & b)
{
	b.f1();      // virtual call
	b.f2();      // virtual call
	b.f3();      // virtual call
	// b.f4();	 // illegal call, no B::f4()
}

/**********************************************************************

$ vf4
B::f1()
B::f2()
B::f3()
******************
B::f1()
D::f2()
B::f3()

*/
