#ifndef __e2node_message__
#define __e2node_message__
namespace e2node {
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
} /* namespace e2node */
#endif /* __e2node_message__ */
