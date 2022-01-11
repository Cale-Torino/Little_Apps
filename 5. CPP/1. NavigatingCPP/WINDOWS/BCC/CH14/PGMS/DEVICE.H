#ifndef DEVICEH
#define DEVICEH
// Device.h - multiple inheritance with multiple inclusion
#include <iostream.h>
#include <typeinfo.h>

class Device {
protected:
	char *const base;							// accessible by derived classes
	char *memptr;								// accessible by derived classes
	enum { IO_Size = 500 };
public:
	Device() : base(new char[IO_Size]), memptr(base) { }
	virtual ~Device() { delete [] base; }
	void reset() { memptr = base; }
};

class ReadDevice : public Device {
public:
	ReadDevice() { }
	~ReadDevice() { }
	virtual void read() = 0;
};

class WriteDevice : public Device {
public:
	WriteDevice() { }
	~WriteDevice() { }
	virtual void write() = 0;
};

class ReadWrite : public WriteDevice, public ReadDevice {
public:
	ReadWrite() { }
	~ReadWrite() { }
};

class CDROM : public ReadDevice {
public:
	void read() { cout << "CDROM::read()" << endl; }
};

class Printer : public WriteDevice {
public:
	void write() { cout << "Printer::write()" << endl; }
};

class Disk : public ReadWrite {
public:
	void read();
	void write() { cout << "Disk::write()" << endl; }
};

void Disk::read() { 
	cout << "Disk::read()" << endl;
	static int count;
	if (ReadDevice::base)								// OK
		ReadDevice::memptr += count;					// OK
	ReadDevice::reset();									// OK
}
#endif
