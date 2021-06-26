#include <project_euler/problem_4_largest_palindrome_product.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;
using namespace testing;

TEST_NL(split_decimal, zero)
{
	auto digits = split_decimal(0U);
	ASSERT_THAT(digits, ElementsAre(0U));
}

TEST_NL(split_decimal, single_digit)
{
	auto digits = split_decimal(1U);
	ASSERT_THAT(digits, ElementsAre(1U));
}

TEST_NL(split_decimal, double_digit)
{
	auto digits = split_decimal(10U);
	ASSERT_THAT(digits, ElementsAre(0U, 1U));
}

TEST_NL(split_decimal, triple_digit)
{
	auto digits = split_decimal(149);
	ASSERT_THAT(digits, ElementsAre(9U, 4U, 1U));
}

TEST_NL(is_palindrome, zero)
{
	ASSERT_TRUE(is_palindrome(0U));
}

TEST_NL(is_palindrome, single_digit)
{
	ASSERT_TRUE(is_palindrome(1U));
}

TEST_NL(is_palindrome, double_digit_invalid)
{
	ASSERT_FALSE(is_palindrome(10U));
}

TEST_NL(is_palindrome, double_digit_valid)
{
	ASSERT_TRUE(is_palindrome(44U));
}

TEST_NL(is_palindrome, valid_odd_number_of_digits)
{
	ASSERT_TRUE(is_palindrome(454U));
}

TEST_NL(largest_palindrome, single_digit)
{
	ASSERT_EQ(largest_palindrome_product(10U), 9U);
}

TEST_NL(largest_palindrome, under_twenty)
{
	ASSERT_EQ(largest_palindrome_product(20U), 323U);
}
