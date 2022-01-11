#ifndef FILEPTRH
#define FILEPTRH
// FilePtr.h - File pointer class

class FilePtr {
private:
	FILE *fp;
public:
// Constructors
	FilePtr(FILE *p) : fp(p) { }
	FilePtr(FilePtr & rhs) : fp(rhs.release()) { }
// Modifiers
	FilePtr & operator=(FilePtr & rhs) {
		if (this != &rhs)
			reset(rhs.release());
		return *this;
	}
	FILE *release() {
		FILE *oldfp = fp;
		fp = 0;
		return oldfp;
	}
	void reset(FILE *p) {
		if (fp) {
			fclose(fp);
		}
		fp = p;
	}
// Destructor
	~FilePtr() { 
		if (fp) {
			fclose(fp);
		}
	}
// Selectors
	FILE *get() const { return fp; }
};
#endif

/*************************************************************************

NOTES:
	1. This FilePtr class is similar to the  auto_ptr class from the chapter.

	2. The copy constructor and overloaded assignment operator require
		helper functions reset() and release().

	3. The reset() function releases the FILE resource with fclose(), whereas
		release() sets the FILE pointer to zero and returns the old pointer.
		This prevents more than one FilePtr object pointing to the same file
		during copy initialization and assignment.

	4. Note that we test fp for zero values before calling fclose().

*/
