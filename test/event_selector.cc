#include "mock_event_selector.h"

using namespace std::chrono_literals;
using ::testing::_;

class fake_event : public e2node::event {
public:
	fake_event(int fd) : fd(fd) { /* Nothing */ }
	~fake_event() { /* Nothing */ }
	int get_event_fd() const { return this->fd; }
private:
	int fd;
};

TEST(EventSelectorTest, SimpleTest)
{
	mock_event_selector es;
	fake_event ev(3);
	es.add_event_watcher(ev, POLLIN | POLLOUT);

	EXPECT_CALL(es, poll(_, 1, 10000));
	es.wait_for_event(10000ms);
}
