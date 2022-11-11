#include <cstdlib>
#include <cerrno>
#include <e2node/event_selector.h>

using namespace std::chrono_literals;

namespace e2node {
event_selector::event_selector() : events()
{ /* Nothing */ }

void event_selector::add_event_watcher(const event &ev, short flags)
{
	this->events.insert({ ev.get_event_fd(), flags });
}

void event_selector::do_wait(const int timeout)
{
	int nfds = events.size(), i = 0;
	struct pollfd *fds = (struct pollfd *)calloc(nfds, sizeof(struct pollfd));

	for (auto iter = events.begin(); iter != events.end(); iter++, i++) {
		fds[i].fd = iter->first;
		fds[i].events = iter->second;
		fds[i].revents = 0;
	}

	if(this->poll(fds, nfds, timeout) == -1)
		throw errno; // GCOVR_EXCL_LINE
}

/**
 * Low level api, provides a overridable interface to sys_poll.
 * @see man poll(2)
 */
// GCOVR_EXCL_START
int event_selector::poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	return ::poll(fds, nfds, timeout);
}

}
// GCOVR_EXCL_STOP
