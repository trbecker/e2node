#ifndef __value_generator_h__
#define __value_generator_h__
#include <map>
#include <memory>  /* std::shared_ptr */

#include <value.h>
#include "types.h"


namespace E2Node {

using ValueMap = std::map<value_name_t, std::shared_ptr<Value>>;

class ValueGenerator {
public:
	ValueGenerator();
	ValueGenerator(ValueGenerator& other);
	virtual ~ValueGenerator();

	void addValue(Value *value);

private:
	ValueMap valueMap;
#ifdef TESTING
	friend ValueMap& getValueGeneratorInternalMap(ValueGenerator *);
#endif
};

#ifdef TESTING
ValueMap& getValueGeneratorInternalMap(ValueGenerator *);
#endif

} /* namespace E2Node */
#endif /* __value_generator_h__ */
