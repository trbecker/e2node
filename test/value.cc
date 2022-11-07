#include <gtest/gtest.h>
#include <e2node/value_generator.h>

namespace e2node {
ValueMap& getValueGeneratorInternalMap(ValueGenerator *gen) {
	return gen->valueMap;
}
} /* namespace e2node */

class FixedValue : public ::e2node::Value {
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
	e2node::ValueGenerator *valueGen;
};

void ValueGeneratorTest::SetUp() {
	this->valueGen = new e2node::ValueGenerator;
}

void ValueGeneratorTest::TearDown() {
	delete this->valueGen;
}

TEST_F(ValueGeneratorTest, TestInitialConditions) {
	EXPECT_TRUE(e2node::getValueGeneratorInternalMap(this->valueGen).empty());
}

TEST_F(ValueGeneratorTest, TestValueAdd) {
	e2node::Value *value = new FixedValue("test_1", 5);
	EXPECT_EQ(value->getValue(), 5);
	EXPECT_NO_THROW({ valueGen->addValue(value); });
	e2node::ValueMap &vm = e2node::getValueGeneratorInternalMap(this->valueGen);
	EXPECT_EQ(vm.size(), 1);
	EXPECT_EQ(vm["test_1"].get(), value);
}

TEST_F(ValueGeneratorTest, TestGetValues) {
	e2node::Value *value1, *value2, *value3;
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
	e2node::ValueGenerator vg;
	std::list<value_name_t> names({ "nonexistant" });
	std::map<value_name_t, int> values;
	EXPECT_NO_THROW({ vg.getValues(names, values); });
	EXPECT_TRUE(values.empty());
}
