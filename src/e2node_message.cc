#include <e2node_message.h>

namespace E2Node {

Message::Message(void *_data) : data(_data) {}
Message::~Message() {
	delete this->data;
}

} /* namespace E2Node */
