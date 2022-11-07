#ifndef __e2node_value_h__
#define __e2node_value_h__
#include <e2node/types.h>
namespace e2node {
class Value {
public:
	Value(value_name_t name);
	virtual int getValue() = 0;
	const value_name_t name;
};
} /* namespace e2node */

#endif /* __e2node_value_h__ */
