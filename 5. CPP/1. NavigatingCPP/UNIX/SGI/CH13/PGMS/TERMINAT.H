#ifndef TERMINATEH
#define TERMINATEH
// Terminate.h - Controls uncaught exceptions

typedef void (*PTRF)();
PTRF set_terminate(PTRF);

class Terminate {
private:
	PTRF old;
public:
	Terminate(PTRF fn) { old = set_terminate(fn); }
	~Terminate() { set_terminate(old); }
};
#endif
