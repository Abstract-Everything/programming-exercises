#include <project_euler/problem_1_multiples_of_3_and_5.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(multiples_of_3_and_5, sum_up_to_3)
{
	unsigned int sum = sum_multiples_of_3_5(3);
	ASSERT_EQ(sum, 3);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_5)
{
	unsigned int sum = sum_multiples_of_3_5(5);
	ASSERT_EQ(sum, 8);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_15)
{
	unsigned int sum = sum_multiples_of_3_5(15);
	ASSERT_EQ(sum, 60);
}
