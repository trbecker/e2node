#ifndef __e2node_simluator_values_h__
#define __e2node_simluator_values_h__
#include <random>
#include <e2node/value_generator.h>

using e2node::Value;

namespace e2simulator {
class ConstantValue : public Value {
public:
	ConstantValue(value_name_t name, int value);
	int getValue() override;

private:
	const int _value;
};

/**
 * Chooses a random value from an a evenly distributed range of values.
 */
class RandomValue : public Value {
public:
	RandomValue(value_name_t name, int start, int end);
	int getValue() override;	

protected:
	std::uniform_int_distribution<int> _distribution;
};

/**
 * Chooses a random value from a normally distributed range of values.
 */
class NormalValue : public Value {
public:
	/**
	 * Constructs the normal distribution
	 * @name The name of the value.
	 * @center The central value of the distribution
	 * @stdev The standard deviation of the distribution.
	 */ 
	NormalValue(value_name_t name, double center, double stdev);

	/** @see Value::getValue */
	int getValue() override;

private:
	std::normal_distribution<double> _distribution;
};
} /* namespace e2simulator */

#endif /* __e2node_simluator_values_h__ */
