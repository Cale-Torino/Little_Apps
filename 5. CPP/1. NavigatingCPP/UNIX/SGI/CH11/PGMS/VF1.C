// vf1.C - virtual function example
#include "Base.h"

int main()
{
  void func(B&);
  B b1;
  D d1;
  func(b1);
  func(d1);
  return 0;
}

void func(B & b)
{
	b.f1();      					// virtual call
	b.f2();      					// virtual call
	b.f3();      					// non-virtual call
}

/**********************************************************************

$ vf1
B::f1()
B::f2()
B::f3()
D::f1()
D::f2()
B::f3()

*/
