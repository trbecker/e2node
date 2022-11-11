#ifndef __e2node_timer_manager__
#define __e2node_timer_manager__
#include <sys/timerfd.h>
#include <unistd.h>
#include <map>

namespace e2node {

class TimerManager;

class Timer {
public:
	Timer(struct itimerspec *timerSpec, void *timerData, int fd);
	~Timer();

private:
	void *timerData;
	struct itimerspec *timerSpec;
	const int fd;

	friend class TimerManager;
};

class TimerManager {
public:
	TimerManager();
	virtual ~TimerManager();
	int createTimer(int interval_secs, void *timerData) noexcept(false);
	int createTimer(int interval_secs, int interval_nsecs, void *timerData) noexcept(false);
	void deleteTimer(int fd);
	void *getTimerData(int fd);

protected:
	virtual int timerfd_create(int flags);

private:
#ifdef TESTING
	friend std::map<int, Timer *>& getInternalMap(TimerManager *);
#endif
	int createTimer(struct itimerspec *timerSpec, void *timerData) noexcept(false);
	std::map<int, Timer *> timers;
};

// Testing stuff.
#ifdef TESTING
std::map<int, Timer *>& getInternalMap(TimerManager *);
#endif
} /* namespace e2node */
#endif /* __e2node_timer_manager__ */
