#include <project_euler/problem_12_highly_divisible_triangular_number.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(highly_divisible_triangular_number, count_factors_one)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::number_of_factors(1U), 1U);
}

TEST_NL(highly_divisible_triangular_number, count_factors_two)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::number_of_factors(2U), 2U);
}

TEST_NL(highly_divisible_triangular_number, count_factors_six)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::number_of_factors(6U), 4U);
}

TEST_NL(highly_divisible_triangular_number, count_factors_eleven)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::number_of_factors(11U), 2U);
}

TEST_NL(highly_divisible_triangular_number, count_factors_twenty_eight)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::number_of_factors(28U), 6U);
}

TEST_NL(highly_divisible_triangular_number, first_with_one_divisor)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::Naive(1U), 1U);
}

TEST_NL(highly_divisible_triangular_number, first_with_two_divisors)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::Naive(2U), 3U);
}

TEST_NL(highly_divisible_triangular_number, first_with_six_divisors)
{
	ASSERT_EQ(Highly_Divisible_Triangular_Number::Naive(6U), 28U);
}
