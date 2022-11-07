#include <sstream>
#include <e2node_message.h>
#include <gtest/gtest.h>

TEST(MessageTest, ContructorAndDestructor) {
	std::stringstream *string = new std::stringstream("Hello, World!");
	E2Node::Message *message1 = new E2Node::Message(string);
	delete message1;
}
