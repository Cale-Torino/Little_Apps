#ifndef STCH
#define STCH
// STC.h - template class for EXCEPTION handlers

typedef void (*PFV)();
PFV set_unexpected(PFV);
PFV set_terminate(PFV);

class Unexpected {
private:
   PFV old;
public:
   Unexpected(PFV fn) { old = set_unexpected(fn); }
   ~Unexpected() { set_unexpected(old); }
};

class Terminate {
private:
   PFV old;
public:
   Terminate(PFV fn) { old = set_terminate(fn); }
   ~Terminate() { set_terminate(old); }
};

template <class EXCEPTION>
class STC {
private:
   EXCEPTION e;
public:
   STC(PFV fn) : e(fn) { }
};
#endif
