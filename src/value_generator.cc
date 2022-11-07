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

void ValueGenerator::getValues(const std::list<value_name_t>& names, std::map<value_name_t, int>& result) {
	for(std::list<value_name_t>::const_iterator it = names.begin() ; it != names.end() ; it++) {
		auto v = this->valueMap[*it];
		if (!v)
			continue;
		result.insert({ *it, v->getValue() });
	}
}
} /* namespace E2Node */
