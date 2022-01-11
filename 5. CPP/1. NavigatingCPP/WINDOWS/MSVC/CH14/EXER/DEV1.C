// dev1.C - Multiple inclusion
#include "Device.h"
#include "PtrList.h"

void process_read(const PtrList<ReadDevice> &);
void process_write(const PtrList<WriteDevice> &);

int main()
{
	PtrList<Device> dlist;							// list of Device *
	//dlist.append(new Disk);						// illegal
	//dlist.append(static_cast<ReadDevice *>(new Disk));		// ugly
	for (PtrIterator<Device> d_iter(dlist); !d_iter; d_iter++) {
		//d_iter()->read();							// illegal, no read in Device
	}

	PtrList<ReadDevice> rlist;						// list of ReadDevice *
	rlist.append(new CDROM);						// CDROM #1, put on read list
	rlist.append(new CDROM);						// CDROM #2, put on read list
	rlist.append(new Keyboard);					// Keyboard, put on read list

	Disk *dp1 = new Disk;							// Disk #1
	rlist.append(dp1);								// put on read list

	Disk *dp2 = new Disk;							// Disk #2
	rlist.append(dp2);								// put on read list

	PtrList<WriteDevice> wlist;					// list of WriteDevice *
	wlist.append(new Printer);						// Printer #1, put on write list
	wlist.append(new Printer);						// Printer #2, put on write list
	wlist.append(new Screen);						// Screen, put on write list

	wlist.append(dp1);								// Disk #1, put on write list
	wlist.append(dp2);								// Disk #2, put on write list

	process_read(rlist);
	process_write(wlist);

	// we have to remove Disk from one list, since its on BOTH lists
	// otherwise, the list destructors will attempt to "delete" it twice
	for (PtrIterator<ReadDevice> r_iter(rlist); !r_iter; r_iter++)
		if (typeid(*r_iter()) == typeid(Disk)) rlist.remove(r_iter);
	return 0;
}

void process_read(const PtrList<ReadDevice> & rlist) {
	for (PtrIterator<ReadDevice> r_iter(rlist); !r_iter; r_iter++)
		r_iter()->read();						// virtual call
}

void process_write(const PtrList<WriteDevice> & wlist) {
	for (PtrIterator<WriteDevice> w_iter(wlist); !w_iter; w_iter++)
		w_iter()->write();					// virtual call
}

/**********************************************************************

$ dev1 
CDROM::read()
CDROM::read()
Keyboard::read()
Disk::read()
Disk::read()
Printer::write()
Printer::write()
Screen::write()
Disk::write()
Disk::write()

*/
