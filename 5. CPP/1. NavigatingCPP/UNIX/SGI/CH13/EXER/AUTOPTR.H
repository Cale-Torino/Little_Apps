#ifndef AUTOPTRH
#define AUTOPTRH
// autoptr.h - auto_ptr and auto_ptr_array

template <class TYPE>
class auto_ptr {
private:
	TYPE *ptr;										// generic pointer
	mutable bool owner;							// ownership
	void copy(const auto_ptr<TYPE> & rhs) {
		if (ptr != rhs.ptr)
			owner = rhs.owner;
		else
			owner |= rhs.owner;
		ptr = rhs.release();
	}
	void free() {
		if (owner) 
			delete ptr;
	}
public:
// Constructor
	explicit auto_ptr(TYPE *p = 0) throw() : 
		ptr(p), owner(p ? true : false) { }
// Copy Constructor
	auto_ptr(const auto_ptr<TYPE> & rhs)  throw() : 
		ptr(0), owner(false) { copy(rhs); }
// Destructor
	~auto_ptr() { free(); }
// Member Functions
	auto_ptr<TYPE> & operator=(const auto_ptr<TYPE> & rhs) throw() {
		if (this != &rhs) {
			if (ptr != rhs.ptr) 
				free();
			copy(rhs);
		}
		return *this;
	}
	TYPE & operator *() const throw() { return *ptr; }
	TYPE * operator->() const throw() { return ptr; }
	TYPE *get() const throw() { return ptr; }
	TYPE *release() const throw() {
		owner = false;								// release ownership
		return ptr;
	}
};

template <class TYPE>
class auto_ptr_array {
private:
	TYPE *ptr;										// generic pointer
	mutable bool owner;							// ownership
	void copy(const auto_ptr_array<TYPE> & rhs) {
		if (ptr != rhs.ptr)
			owner = rhs.owner;
		else
			owner |= rhs.owner;
		ptr = rhs.release();
	}
	void free() {
		if (owner) 
			delete [] ptr;
	}
public:
// Constructor
	explicit auto_ptr_array(TYPE *p = 0) throw() : 
		ptr(p), owner(p ? true : false) { }
// Copy Constructor
	auto_ptr_array(const auto_ptr_array<TYPE> & rhs)  throw() : 
		ptr(0), owner(false) { copy(rhs); }
// Destructor
	~auto_ptr_array() { free(); }
// Member Functions
	auto_ptr_array<TYPE> & operator=(const auto_ptr_array<TYPE> & rhs) throw() {
		if (this != &rhs) {
			if (ptr != rhs.ptr) 
				free();
			copy(rhs);
		}
		return *this;
	}
	TYPE & operator *() const throw() { return *ptr; }
	TYPE * operator->() const throw() { return ptr; }
	TYPE & operator[](int i) { return ptr[i]; }
	const TYPE & operator[](int i) const { return ptr[i]; }
	TYPE *get() const throw() { return ptr; }
	TYPE *release() const throw() {
		owner = false;								// release ownership
		return ptr;
	}
};
#endif
