#ifndef __e2node_processor__
#define __e2node_processor__
namespace e2node {

/**
 * processor is the main process
 */
class processor {
public:
	processor();
	virtual ~processor();

	void run();
	void stop();
	bool is_running();

protected:
	void start();
	void wait_for_message();
	void process_message();
	void shutdown();

private:
	bool running;
};

} /* namespace e2node */

#endif /* __e2node_processor__ */
