#include <value_generator.h>

namespace E2Node {

ValueGenerator::ValueGenerator() : valueMap() { }

ValueGenerator::~ValueGenerator()
{
	// Empty	
}

void ValueGenerator::addValue(Value *value)
{
	this->valueMap.insert({ value->name, std::shared_ptr<Value>(value) });	
}

} /* namespace E2Node */
