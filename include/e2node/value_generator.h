#ifndef __e2node_value_generator_h__
#define __e2node_value_generator_h__
#include <map>
#include <memory>  /* std::shared_ptr */
#include <list>

#include <e2node/value.h>
#include <e2node/types.h>


namespace e2node {

using ValueMap = std::map<value_name_t, std::shared_ptr<Value>>;

class ValueGenerator {
public:
	ValueGenerator();
	virtual ~ValueGenerator();

	void addValue(Value *value);
	void getValues(const std::list<value_name_t>&, std::map<value_name_t, int>&);

private:
	ValueMap valueMap;
#ifdef TESTING
	friend ValueMap& getValueGeneratorInternalMap(ValueGenerator *);
#endif
};

#ifdef TESTING
ValueMap& getValueGeneratorInternalMap(ValueGenerator *);
#endif

} /* namespace e2node */
#endif /* __e2node_value_generator_h__ */
