#include <project_euler/problem_10_summation_of_primes.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(summation_of_primes, summation_of_primes_under_ten)
{
	std::size_t result = 2 + 3 + 5 + 7;
	ASSERT_EQ(Summation_Of_Primes::Naive(10U), result);
}
