#ifndef __e2node_mock_event_selector__
#define __e2node_mock_event_selector__

#include <e2node/event_selector.h>
#include <gmock/gmock.h>

class mock_event_selector : public e2node::event_selector {
public:
	mock_event_selector() : event_selector() { /* Nothing */ }
	MOCK_METHOD(int, poll, (struct pollfd *fds, nfds_t nfds, int timeout), (override));
};
#endif
