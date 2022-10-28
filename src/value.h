#ifndef __value_h__
#define __value_h__
#include "types.h"
namespace E2Node {
class Value {
public:
	Value(value_name_t name);
	virtual int getValue() = 0;
	const value_name_t name;
};
} /* namespace E2Simulator */

#endif
