// mp1.c - class specific overloading new and delete, memory pools
#include "A1.h"

int main()
{
	try {
		 A *p1 = new A;							// A::new(sizeof(A))
		 A *p2 = new A;							// A::new(sizeof(A))
		 A *p3 = new A;							// A::new(sizeof(A))
		 A *p4 = new A;							// A::new(sizeof(A))
		 A *p5 = new A;							// A::new(sizeof(A))
		 A *p6 = new A;							// A::new(sizeof(A))
		 A *p7 = new A;							// A::new(sizeof(A))
		 A *p8 = new A;							// A::new(sizeof(A))
		 A *p9 = new A;							// A::new(sizeof(A))
		 A *pa = new A;							// A::new(sizeof(A))
		 A *pb = new A;							// A::new(sizeof(A))

		 delete p1;
		 delete p2;
		 delete p3;
		 delete p4;
		 delete p5;
		 delete p6;
		 delete p7;
		 delete p8;
		 delete p9;
		 delete pa;
		 delete pb;
	}
	catch (const MpoolError & e) {
		e.response();
		A::free_pool();						// free Memory pool
		return 1;
	}
	A::free_pool();							// free Memory pool
	return 0;
}

/**********************************************************************

$ mp1 
Mpool constr(size, nitems): 4,256
Mpool::alloc - 0x10014610
Mpool::alloc - 0x10014614
Mpool::alloc - 0x10014618
Mpool::alloc - 0x1001461c
Mpool::alloc - 0x10014620
Mpool::alloc - 0x10014624
Mpool::alloc - 0x10014628
Mpool::alloc - 0x1001462c
Mpool::alloc - 0x10014630
Mpool::alloc - 0x10014634
Mpool::alloc - 0x10014638
Mpool::dealloc - 0x10014610
Mpool::dealloc - 0x10014614
Mpool::dealloc - 0x10014618
Mpool::dealloc - 0x1001461c
Mpool::dealloc - 0x10014620
Mpool::dealloc - 0x10014624
Mpool::dealloc - 0x10014628
Mpool::dealloc - 0x1001462c
Mpool::dealloc - 0x10014630
Mpool::dealloc - 0x10014634
Mpool::dealloc - 0x10014638
Mpool destructor

*/
