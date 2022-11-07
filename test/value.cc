#include <gtest/gtest.h>
#include <value_generator.h>

namespace E2Node {
ValueMap& getValueGeneratorInternalMap(ValueGenerator *gen) {
	return gen->valueMap;
}
} /* namespace E2Node */

class FixedValue : public ::E2Node::Value {
public:
	FixedValue(value_name_t name, int value) : value(value), Value(name) { }

	int getValue() {
		return this->value;
	}
private:
	const int value;
};

class ValueGeneratorTest : public ::testing::Test {
protected:
	void SetUp() override;
	void TearDown() override;
	E2Node::ValueGenerator *valueGen;
};

void ValueGeneratorTest::SetUp() {
	this->valueGen = new E2Node::ValueGenerator;
}

void ValueGeneratorTest::TearDown() {
	delete this->valueGen;
}

TEST_F(ValueGeneratorTest, TestInitialConditions) {
	EXPECT_TRUE(E2Node::getValueGeneratorInternalMap(this->valueGen).empty());
}

TEST_F(ValueGeneratorTest, TestValueAdd) {
	E2Node::Value *value = new FixedValue("test_1", 5);
	EXPECT_EQ(value->getValue(), 5);
	EXPECT_NO_THROW({ valueGen->addValue(value); });
	E2Node::ValueMap &vm = E2Node::getValueGeneratorInternalMap(this->valueGen);
	EXPECT_EQ(vm.size(), 1);
	EXPECT_EQ(vm["test_1"].get(), value);
}

TEST_F(ValueGeneratorTest, TestGetValues) {
	E2Node::Value *value1, *value2, *value3;
	value1 = new FixedValue("value1", 1);
	value2 = new FixedValue("value2", 2);
	value3 = new FixedValue("value3", 3);

	this->valueGen->addValue(value1);
	this->valueGen->addValue(value2);
	this->valueGen->addValue(value3);

	std::map<value_name_t, int> values;
	std::list<value_name_t> names({ "value2" });

	this->valueGen->getValues(names, values);
	EXPECT_EQ(values["value2"], 2);
	values.clear();

	names.push_back("value1");

	this->valueGen->getValues(names, values);
	EXPECT_EQ(values["value2"], 2);
	EXPECT_EQ(values["value1"], 1);
}

TEST(ValueGeneratorTest2, TestFailGetValue) {
	E2Node::ValueGenerator vg;
	std::list<value_name_t> names({ "nonexistant" });
	std::map<value_name_t, int> values;
	EXPECT_NO_THROW({ vg.getValues(names, values); });
	EXPECT_TRUE(values.empty());
}
