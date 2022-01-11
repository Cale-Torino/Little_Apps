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
Mpool::alloc - 0x0065027C
Mpool::alloc - 0x00650280
Mpool::alloc - 0x00650284
Mpool::alloc - 0x00650288
Mpool::alloc - 0x0065028C
Mpool::alloc - 0x00650290
Mpool::alloc - 0x00650294
Mpool::alloc - 0x00650298
Mpool::alloc - 0x0065029C
Mpool::alloc - 0x006502A0
Mpool::alloc - 0x006502A4
Mpool::dealloc - 0x0065027C
Mpool::dealloc - 0x00650280
Mpool::dealloc - 0x00650284
Mpool::dealloc - 0x00650288
Mpool::dealloc - 0x0065028C
Mpool::dealloc - 0x00650290
Mpool::dealloc - 0x00650294
Mpool::dealloc - 0x00650298
Mpool::dealloc - 0x0065029C
Mpool::dealloc - 0x006502A0
Mpool::dealloc - 0x006502A4
Mpool destructor

*/
