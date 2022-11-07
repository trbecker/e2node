#include <e2node/timer_manager.h>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <exception>
#include <iostream>


namespace e2node {
class TimerException : std::exception {
public:
	TimerException(const char *err);
	const char *what();
private:
	const char *err;
};


TimerException::TimerException(const char *err) :
	err(err) { }

const char *TimerException::what() {
	return this->err;
}

// class Timer
Timer::Timer(struct itimerspec *timerSpec, void *timerData, int fd) : fd(fd),
	timerData(timerData), timerSpec(timerSpec) {}

Timer::~Timer()
{
	/* 
	 * This is not thread safe.
	 * To fix, we need a reference counter and get/put methods to protect from use after free
	 * and a mutex to protect against change.
	 */
	free(this->timerData);
	free(this->timerSpec);
	close(this->fd);
}

// class TimerManager
TimerManager::TimerManager() : timers()
{

}

TimerManager::~TimerManager()
{

}

int TimerManager::createTimer(struct itimerspec *timerSpec, void *timerData) noexcept(false)	
{
	/*
	 * Since we are interested in periodic intervals for updates,
	 * we choose the monotonic clock. The monotonic clock provides
	 * a tick even when the system clock is reset, and not wake up
	 * the system when the system is suspended.
	 */
	int fd = timerfd_create(CLOCK_MONOTONIC, 0);
	if (fd < 0) {
		throw TimerException(strerror(errno));
	}

	Timer *timer = new Timer(timerSpec, timerData, fd);
	// Using .insert to raise an exception if the fd is
	// duplicated.
	timers.insert({ fd, timer });

	return fd;
}

int TimerManager::createTimer(int interval_secs, int interval_nsecs, void *timerData) noexcept(false)
{
	struct itimerspec *timerSpec = (struct itimerspec *)malloc(sizeof(struct itimerspec));
	timerSpec->it_value.tv_sec = interval_secs;
	timerSpec->it_value.tv_nsec = interval_nsecs;
	timerSpec->it_interval.tv_sec = interval_secs;
	timerSpec->it_interval.tv_nsec = interval_nsecs;

	return this->createTimer(timerSpec, timerData);

}

int TimerManager::createTimer(int interval_secs, void *timerData) noexcept(false)
{
	return this->createTimer(interval_secs, 0, timerData);
}

void TimerManager::deleteTimer(int fd)
{
	Timer *t = timers[fd];
	timers.erase(fd);
	delete t;
}

void *TimerManager::getTimerData(int fd)
{
	return timers[fd]->timerData;
}
} /* namesapce e2node */
