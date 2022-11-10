#include <e2node/processor.h>

namespace e2node {
processor::processor() : running(false) { }
processor::~processor() { }

void processor::run() {
	this->running = true;
	this->start();
	while (this->running) {
		this->wait_for_message();
		this->process_message();
	}
	this->shutdown();
}

void processor::start()
{
	// TBD
}

void processor::stop()
{
	this->running = false;
}

bool processor::is_running()
{
	return this->running;
}

void processor::wait_for_message()
{
	// TBD
}

void processor::process_message()
{
	// TBD
}

void processor::shutdown()
{
	// TBD
}
}
