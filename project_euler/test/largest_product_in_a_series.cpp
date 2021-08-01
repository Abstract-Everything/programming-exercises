#include <project_euler/problem_8_largest_product_in_a_series.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(largest_product_in_a_series, single_digit_series_one)
{
	ASSERT_EQ(Largest_Product_In_A_Series::Naive("1", 1U), 1U);
}

TEST_NL(largest_product_in_a_series, single_digit_series_two)
{
	ASSERT_EQ(Largest_Product_In_A_Series::Naive("2", 1U), 2U);
}

TEST_NL(largest_product_in_a_series, multiple_digits_series)
{
	ASSERT_EQ(Largest_Product_In_A_Series::Naive("2345", 1U), 5U);
}

TEST_NL(largest_product_in_a_series, multiple_digits_series_substring_two)
{
	ASSERT_EQ(Largest_Product_In_A_Series::Naive("2345", 2U), 20U);
}

TEST_NL(largest_product_in_a_series, multiple_digits_series_substring_four)
{
	ASSERT_EQ(Largest_Product_In_A_Series::Naive(Largest_Product_In_A_Series::problem_string, 4U), 5832U);
}

TEST_NL(largest_product_in_a_series, substring_larger_than_series)
{
	ASSERT_EQ(Largest_Product_In_A_Series::Naive("1", 2U), 0U);
}

