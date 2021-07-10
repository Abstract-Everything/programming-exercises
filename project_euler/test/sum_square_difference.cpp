#include <project_euler/problem_6_sum_square_difference.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(sum_square_difference, up_to_one)
{
	ASSERT_EQ(sum_square_difference(1U), 0U);
}

TEST_NL(sum_square_difference, up_to_two)
{
	ASSERT_EQ(sum_square_difference(2U), 4U);
}

TEST_NL(sum_square_difference, up_to_ten)
{
	ASSERT_EQ(sum_square_difference(10U), 2640U);
}

