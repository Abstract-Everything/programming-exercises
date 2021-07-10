#include <project_euler/problem_2_even_fibonacci_numbers.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(even_fibonacci_numbers, even_sum_of_one_is_zero)
{
	ASSERT_EQ(accumulate_even_fibonacci(1), 0);
}

TEST_NL(even_fibonacci_numbers, even_sum_of_two_is_two)
{
	ASSERT_EQ(accumulate_even_fibonacci(2), 2);
}

TEST_NL(even_fibonacci_numbers, accumulate_terms_up_to_ten)
{
	ASSERT_EQ(accumulate_even_fibonacci(10), 10);
}
