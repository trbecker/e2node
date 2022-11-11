#ifndef __e2node_processor__
#define __e2node_processor__
#include <e2node/e2.h>
namespace e2node {

/**
 * processor is the main process
 */
class processor {
public:
	processor(e2 *e2impl);
	virtual ~processor();

	void start(sock_info &peer);
	void stop();
	bool is_running();

protected:
	void setup(sock_info &peer);
	void wait_for_message();
	void process_message();
	void shutdown();

private:
	bool running;
	e2 *e2impl;
};

} /* namespace e2node */

#endif /* __e2node_processor__ */
