#include <e2node/processor.h>

namespace e2node {
processor::processor(e2 *e2impl) : 
	running(false), e2impl(e2impl) { /* Nothing */ }
processor::~processor()
{ /* Nothing */ }

void processor::start(sock_info &peer) {
	this->running = true;
	this->setup(peer);
	while (this->running) {
		this->wait_for_message();
		this->process_message();
	}
	this->shutdown();
}

void processor::setup(sock_info &peer)
{
	this->e2impl->connect(peer);
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
