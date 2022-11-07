#include <sstream>
#include <e2node/message.h>
#include <gtest/gtest.h>

TEST(MessageTest, ContructorAndDestructor) {
	std::stringstream *string = new std::stringstream("Hello, World!");
	e2node::Message *message1 = new e2node::Message(string);
	delete message1;
}
