#include <project_euler/problem_6_sum_square_difference.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(sum_square_difference, up_to_one)
{
	ASSERT_EQ(Sum_Square_Difference::Naive(1U), 0U);
}

TEST_NL(sum_square_difference, up_to_two)
{
	ASSERT_EQ(Sum_Square_Difference::Naive(2U), 4U);
}

TEST_NL(sum_square_difference, up_to_ten)
{
	ASSERT_EQ(Sum_Square_Difference::Naive(10U), 2640U);
}

TEST_NL(sum_square_difference, up_to_ten_optimized)
{
	std::size_t sum_naive = Sum_Square_Difference::Naive(10U);
	std::size_t sum_optimized = Sum_Square_Difference::Optimized(10U);
	ASSERT_EQ(sum_naive, sum_optimized);
}
