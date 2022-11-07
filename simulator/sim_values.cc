#include "sim_values.h"

namespace e2simulator {

static std::default_random_engine generator;

ConstantValue::ConstantValue(value_name_t name, int value) :
	Value(name), _value(value) {}

int ConstantValue::getValue()
{
	return this->_value;
}

// =========================
RandomValue::RandomValue(value_name_t name, int start, int end) :
	Value(name), _distribution(start, end) { }

int RandomValue::getValue()
{
	return this->_distribution(generator);	
}

// =========================
NormalValue::NormalValue(value_name_t name, double mean, double stdev) :
	Value(name), _distribution(mean, stdev) { }

int NormalValue::getValue()
{
	return (int)this->_distribution(generator);
}

} /* namespace e2simulator */
