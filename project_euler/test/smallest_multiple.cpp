#include <project_euler/problem_5_smallest_multiple.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(smallest_multiple, single_digit)
{
	ASSERT_EQ(smallest_multiple(2U), 2U);
}

TEST_NL(smallest_multiple, two_digits)
{
	const std::size_t multiple = 2 * 2 * 3;
	ASSERT_EQ(smallest_multiple(4U), multiple);
}

TEST_NL(smallest_multiple, ten_digits)
{
	const std::size_t multiple = 2 * 2 * 2 * 3 * 3 * 5 * 7;
	ASSERT_EQ(smallest_multiple(10U), multiple);
}
