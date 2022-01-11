#ifndef FILEPTRH
#define FILEPTRH
// FilePtr.h - File pointer class

class FilePtr {
private:
	FILE *fp;
	FilePtr(const FilePtr &);						// disable copy constr
	FilePtr & operator=(const FilePtr &);		// disable assignment
public:
// Constructor
	FilePtr(FILE *p) : fp(p) { }
// Destructor
	~FilePtr() { fclose(fp); }						// close file
	FILE *get() const { return fp; }
};
#endif
