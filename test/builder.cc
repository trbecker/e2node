#include "../simulator/node_builder.h"
#include <gtest/gtest.h>

TEST(BuilderTest, Test)
{
	E2NodeSimulator::E2NodeConstructor builder("node_config_1.yaml");
	std::list<E2Node::Value *> values;
	std::list<std::string> expected_values({ "value1", "value2",
		"value3"});


	builder.getValues(values);

	for (std::list<std::string>::iterator i = expected_values.begin();
			i != expected_values.end(); i++) {	
		bool found = false;
		for (std::list<E2Node::Value *>::iterator it = values.begin();
				 it != values.end() ; it++)
			if (found = ((*it)->name == *i))
				break;
		if (!found)
			FAIL() << *i << " not found";
	}

}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
