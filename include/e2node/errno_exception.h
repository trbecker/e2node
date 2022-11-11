#ifndef __e2node_errno_exceptions__
#define __e2node_errno_exceptions__
#include <exception>
#include <cerrno>
#include <cstring>

/* 
 * GCOVR_EXCL_START
 * These are quite simple classes.
 */
namespace e2node {
class errno_exception : public std::exception {
public:
	errno_exception(int err) : errno_exception(strerror(err)) { /* Nothing */ }
	errno_exception(const char *err) : errno_exception(std::string(err)) { /* Nothing */ }
	errno_exception(const std::string &err) : errstr(err) { /* Nothing */ }

	const char *what() const noexcept override { return this->errstr.c_str(); }

private:
	const std::string errstr;
};

#define DECLARE_ERRNO_EXCEPTION(name) \
class name##_exception : public errno_exception { \
public: \
	name##_exception(int err) : errno_exception(err) {} \
	name##_exception(const char *err) : errno_exception(err) {} \
	name##_exception(const std::string &err) : errno_exception(err) {} \
};

DECLARE_ERRNO_EXCEPTION(poll);
DECLARE_ERRNO_EXCEPTION(sctp);
DECLARE_ERRNO_EXCEPTION(timer);
	
} /* namespace e2node */
/* GCOVR_EXCL_STOP */

#endif /* __e2node_errno_exceptions__ */
