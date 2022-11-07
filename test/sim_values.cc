#include "gtest/gtest.h"

#include "../simulator/sim_values.h"

#define CHECK_VALUE_IN_SEQUENCE(seq, v, size) \
do { \
	bool __c = false; \
	for(int iter = 0; iter <= size; iter++) \
		if(seq[iter] == v) { \
			__c = true; \
			break; \
		} \
	if(__c) SUCCEED(); else FAIL(); \
} while(0)

TEST(ConstantValueTest, Test)
{
	e2simulator::ConstantValue v("constant", 5);
	ASSERT_EQ(v.getValue(), 5);
	ASSERT_STREQ(v.name.c_str(), "constant");
}

#define MRAND_MIN 0
#define MRAND_MAX 6
#define TEST_REPEATS 1000

TEST(RandomValueTest, Test)
{
	e2simulator::RandomValue v("random", MRAND_MIN, MRAND_MAX);
	int *values = (int *)calloc(TEST_REPEATS, sizeof(int));

	for(int i = 0; i < TEST_REPEATS; i++) {
		int _v = v.getValue();
#ifdef PRINT_GENERATED_VALUES
		std::cerr << _v << ", ";
#endif
		ASSERT_TRUE(_v >= 0 && _v <= 6);
		values[i] = _v;
	}

#ifdef PRINT_GENERATED_VALUES
	std::cerr << std::endl;
#endif
	
	// Check if all values are covered (there's a small chance that this fails)
	for(int i = MRAND_MIN; i <= MRAND_MAX; i++)
		CHECK_VALUE_IN_SEQUENCE(values, i, TEST_REPEATS);

	free(values);
}

// This is a harder test, we should test for properties of the normal distribution
// For the time being, test just the basics.
TEST(NormalValueTest, Test)
{
	e2simulator::NormalValue v("normal", 10, 2);
	for(int i = 0; i < TEST_REPEATS; i++) {
		int _v = v.getValue();
#ifdef PRINT_GENERATED_VALUES
		std::cerr << _v << ", ";
#endif
		EXPECT_TRUE(_v < 1000);
	}
#ifdef PRINT_GENERATED_VALUES
	std::cerr << std::endl;
#endif
}
