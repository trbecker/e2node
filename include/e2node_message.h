#ifndef __e2node_message__
#define __e2node_message__
namespace E2Node {
class Message {
public:
	/**
	 * Message constructor. Transfers the control of data to this class.
	 */
	Message(void *);
	virtual ~Message();

private:
	void *data;
}; /* class Message */
} /* namespace E2Node */
#endif /* __e2node_message__ */
