// struct1.C - structures & pointer to structure
#include <iostream.h>

struct block {										// structure type
  int buf[80];										// data member
  char *pheap;										// data member
  void header(const char *);					// member function
};

void block::header(const char * msg) {
	cout << msg << endl;
}
	
int main()
{
	block data = { {1,2,3}, "basic" };				// structure variable
	block *ps = &data;									// structure pointer

	data.pheap++;											// increment data member
	data.header("magic");								// call member function
	ps->pheap++;											// increment data member
	ps->header("magic");									// call member function
	//ps.pheap++;											// illegal, ps is a pointer
	//data->header("magic");							// illegal, data is a structure

	block dbase[2] = {									// array of 2 structures
		{ {1,2,3}, "one" },								// initialize first element
		{ {4,5,6}, "two" }								// initialize second element
	};
	block *pb[2];											// array of 2 pointers to block

	dbase[1].pheap++;										// increment data member
	dbase[1].buf[0] = 'x';								// assign to data member
	dbase[1].header("magic");							// call member function

	pb[1] = &dbase[1];									// pb[1] points to dbase[1]
	pb[1]->pheap++;										// increment data member
	pb[1]->buf[0] = 'x';									// assign to data member
	pb[1]->header("magic");								// call member function
	return 0;
}

/*******************************************************************

$ struct1
magic
magic
magic
magic

*/
