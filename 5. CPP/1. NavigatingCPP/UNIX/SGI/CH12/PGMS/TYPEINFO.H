/* Edison Design Group, 1995. */
/*
typeinfo.h -- Include file for type information (18.5.1)
*/
#ifndef _TYPEINFO_H
#define _TYPEINFO_H

#include <stdexcept.h>

/*
If bool is not supported, use a typedef for bool.
*/
#ifdef _BOOL
typedef bool _bool;
#else /* ifndef _BOOL */
typedef int _bool;
#endif /* ifdef _BOOL */

#if _SGI_NAMESPACES_SUPPORTED
#define EXCEPTION exception
#else
#define EXCEPTION std::exception
#endif

#if _SGI_NAMESPACES_SUPPORTED
namespace std {
#endif /* _SGI_NAMESPACES_SUPPORTED */
/* The following pragma is used so that the compiler knows that this definition
   of type_info is the one that corresponds to the type returned by typeid. */
#pragma define_type_info
  class type_info {
  public:
    virtual ~type_info();
    _bool operator==(const type_info&) const;
    _bool operator!=(const type_info&) const;
    _bool before(const type_info&) const;
    const char* name() const;
  private:
    type_info& operator=(const type_info&);  // Not actually defined
#if 0
#else /* 0 */
  protected:
    // Protected instead of private to suppress the "no accessible
    // constructor" warning
#endif /* 0 */
    type_info(const type_info&);  // Not actually defined
  };

  class bad_cast : public EXCEPTION {
  public:
#if EXCEPTION_HANDLING != 0
    /* FIXME-- Till we bootstrap, we cannot use the throw() syntax */
    bad_cast() throw();
    bad_cast(const bad_cast&) throw();
    bad_cast& operator=(const bad_cast&) throw();
    virtual ~bad_cast() throw();
    virtual const char* what() const throw();
#else
    bad_cast();
    bad_cast(const bad_cast&);
    bad_cast& operator=(const bad_cast&);
    virtual ~bad_cast();
    virtual const char* what() const;
#endif
  };

  class bad_typeid : public EXCEPTION {
  public:
#if EXCEPTION_HANDLING != 0
    /* FIXME-- Till we bootstrap, we cannot use the throw() syntax */
    bad_typeid() throw();
    bad_typeid(const bad_typeid&) throw();
    bad_typeid& operator=(const bad_typeid&) throw();
    virtual ~bad_typeid() throw();
    virtual const char* what() const throw();
#else
    bad_typeid();
    bad_typeid(const bad_typeid&);
    bad_typeid& operator=(const bad_typeid&);
    virtual ~bad_typeid();
    virtual const char* what() const;
#endif
  };

#if _SGI_NAMESPACES_SUPPORTED
}  /* namespace std */
#endif /* _SGI_NAMESPACES_SUPPORTED */

#undef EXCEPTION

#endif /* _TYPEINFO_H */
