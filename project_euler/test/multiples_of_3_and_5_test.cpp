#include <project_euler/problem_1_multiples_of_3_and_5.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(multiples_of_3_and_5, sum_up_to_3)
{
	std::size_t sum = Sum_Multiples_Of_3_And_5::Naive(3);
	ASSERT_EQ(sum, 3);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_5)
{
	std::size_t sum = Sum_Multiples_Of_3_And_5::Naive(5);
	ASSERT_EQ(sum, 8);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_15)
{
	std::size_t sum = Sum_Multiples_Of_3_And_5::Naive(15);
	ASSERT_EQ(sum, 60);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_30)
{
	std::size_t sum = Sum_Multiples_Of_3_And_5::Naive(30);
	ASSERT_EQ(sum, 225);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_30_optimized)
{
	std::size_t sum_naive = Sum_Multiples_Of_3_And_5::Naive(30);
	std::size_t sum_optimized = Sum_Multiples_Of_3_And_5::Optimized(30);
	ASSERT_EQ(sum_naive, sum_optimized);
}

TEST_NL(multiples_of_3_and_5, sum_up_to_999_optimized)
{
	std::size_t sum_naive = Sum_Multiples_Of_3_And_5::Naive(999);
	std::size_t sum_optimized = Sum_Multiples_Of_3_And_5::Optimized(999);
	ASSERT_EQ(sum_naive, sum_optimized);
}
