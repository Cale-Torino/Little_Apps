#ifndef EXCEPTIONH
#define EXCEPTIONH
#include <string.h>

namespace std {
	class exception {
	private:
		char msg[256];
	public:
		exception(const char *m = "") throw () { strcpy(msg, m); }
		virtual ~exception() throw() { }
		virtual const char *what() const throw() { return msg; }
	};

	class logic_error : public exception {
	public:
		logic_error(const char *m) throw () : exception(m) { }
	};

	class runtime_error : public exception {
	public:
		runtime_error(const char *m) throw () : exception(m) { }
	};

	class domain_error : public logic_error {
	public:
		domain_error(const char *m) throw () : logic_error(m) { }
	};

	class invalid_argument : public logic_error {
	public:
		invalid_argument(const char *m) throw () : logic_error(m) { }
	};

	class length_error : public logic_error {
	public:
		length_error(const char *m) throw () : logic_error(m) { }
	};

	class out_of_range : public logic_error {
	public:
		out_of_range(const char *m) throw () : logic_error(m) { }
	};

	class range_error : public runtime_error {
	public:
		range_error(const char *m) throw () : runtime_error(m) { }
	};

	class overflow_error : public runtime_error {
	public:
		overflow_error(const char *m) throw () : runtime_error(m) { }
	};

	class bad_alloc : public exception {
	public:
		bad_alloc() throw() { }
		virtual ~bad_alloc() throw() { }
		const char *what() const throw() { return "no free store memory"; }
	};

	class bad_cast : public exception {
	public:
		bad_cast() throw() { }
		virtual ~bad_cast() throw() { }
		const char *what() const throw() { return "illegal cast"; }
	};

	class bad_typeid : public exception {
	public:
		bad_typeid() throw() { }
		virtual ~bad_typeid() throw() { }
		const char *what() const throw() { return "illegal typeid"; }
	};

	class bad_exception : public exception {
	public:
		bad_exception() throw() { }
		virtual ~bad_exception() throw() { }
		const char *what() const throw() { return "illegal exception"; }
	};
}

using namespace std;
#endif
