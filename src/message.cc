#include <e2node/message.h>

namespace e2node {

Message::Message(void *_data) : data(_data) {}
Message::~Message() {
	delete this->data;
}

} /* namespace e2node */
