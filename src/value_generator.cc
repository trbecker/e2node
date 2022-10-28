#include "value_generator.h"

namespace E2Node {

ValueGenerator::ValueGenerator() : valueMap() { }

ValueGenerator::ValueGenerator(ValueGenerator& other)
{
	// Copy constructor
}

ValueGenerator::~ValueGenerator()
{
	// Empty	
}

void ValueGenerator::addValue(Value *value)
{
	this->valueMap.insert({ value->name, std::shared_ptr<Value>(value) });	
}

#ifdef TESTING
ValueMap& getValueGeneratorInternalMap(ValueGenerator *gen) {
	return gen->valueMap;
}
#endif

} /* namespace E2Node */
