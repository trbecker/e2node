#include "../simulator/node_builder.h"
#include <gtest/gtest.h>

TEST(BuilderTest, Test)
{
	using value_iterator = std::list<std::shared_ptr<e2node::Value>>::iterator;
	e2simulator::E2NodeConstructor builder("node_config_1.yaml");
	std::list<std::shared_ptr<e2node::Value>> values;
	std::list<std::string> expected_values({ "value1", "value2",
		"value3"});


	builder.getValues(values);

	for (std::list<std::string>::iterator i = expected_values.begin();
			i != expected_values.end(); i++) {	
		bool found = false;
		for (value_iterator it = values.begin();
				 it != values.end() ; it++)
			if (found = ((*it)->name == *i))
				break;
		if (!found)
			FAIL() << *i << " not found";
	}

}
