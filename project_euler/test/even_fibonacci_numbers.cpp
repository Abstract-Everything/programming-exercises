#include <project_euler/problem_2_even_fibonacci_numbers.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(even_fibonacci_numbers, even_sum_of_one_is_zero)
{
	ASSERT_EQ(Even_Fibonacci_Numbers::Naive(1), 0);
}

TEST_NL(even_fibonacci_numbers, even_sum_of_two_is_two)
{
	ASSERT_EQ(Even_Fibonacci_Numbers::Naive(2), 2);
}

TEST_NL(even_fibonacci_numbers, accumulate_terms_up_to_ten)
{
	ASSERT_EQ(Even_Fibonacci_Numbers::Naive(10), 10);
}

TEST_NL(even_fibonacci_numbers, accumulate_terms_up_to_ten_optimized)
{
	auto sum_naive = Even_Fibonacci_Numbers::Naive(10);
	auto sum_optimized = Even_Fibonacci_Numbers::Optimized(10);
	ASSERT_EQ(sum_naive, sum_optimized);
}

TEST_NL(even_fibonacci_numbers, accumulate_terms_up_to_four_million_optimized)
{
	auto sum_naive = Even_Fibonacci_Numbers::Naive(4'000'000);
	auto sum_optimized = Even_Fibonacci_Numbers::Optimized(4'000'000);
	ASSERT_EQ(sum_naive, sum_optimized);
}
