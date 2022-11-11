#ifndef __e2node_event_selector__
#define __e2node_event_selector__
/**
 * Defines a set of low level functions to interact with the
 * operating system. This serves specially to mockup functions
 * on automated testing, but also to provide a c++ interface to
 * system calls.
 */
#include <map>
#include <chrono>
#include <sys/poll.h>

using std::chrono::duration;
using namespace std::chrono_literals;

namespace e2node {
class event {
public:
	virtual int get_event_fd() const = 0;
}; /* event */

class event_selector {
public:
	event_selector();

	void add_event_watcher(const event &event, short events);

	template<class Rep, class Period>
	void wait_for_event(const duration<Rep, Period> &timeout);

protected:
	void do_wait(const int timeout);
	virtual int poll(struct pollfd *fds, nfds_t nfds, int timeout);

private:
	std::map<int, short> events;
}; /* class events */

template <class Rep, class Period>
void event_selector::wait_for_event(const duration<Rep, Period> &timeout)
{
	this->do_wait(timeout / 1ms);
}
} /* namespace e2node */

#endif /* __e2node_event_selector__ */
