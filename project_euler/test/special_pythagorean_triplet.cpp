#include <project_euler/problem_9_special_pythagorean_triplet.hpp>

#include <gtest/gtest.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;

TEST_NL(is_pythagorean_triplet, zero_first_argument)
{
	auto [is_triplet, c] = Special_Pythagorean_Triplet::is_pythagorean_triplet(0U, 1U);
	EXPECT_FALSE(is_triplet);
}

TEST_NL(is_pythagorean_triplet, zero_second_argument)
{
	auto [is_triplet, c] = Special_Pythagorean_Triplet::is_pythagorean_triplet(0U, 1U);
	EXPECT_FALSE(is_triplet);
}

TEST_NL(is_pythagorean_triplet, first_pair)
{
	auto [is_triplet, c] = Special_Pythagorean_Triplet::is_pythagorean_triplet(3U, 4U);
	EXPECT_TRUE(is_triplet);
	EXPECT_EQ(c, 5U);
}

TEST_NL(is_pythagorean_triplet, invalid_pair)
{
	auto [is_triplet, c] = Special_Pythagorean_Triplet::is_pythagorean_triplet(1U, 2U);
	EXPECT_FALSE(is_triplet);
}

TEST_NL(is_pythagorean_triplet, invalid_pair_precision_test)
{
	auto [is_triplet, c] = Special_Pythagorean_Triplet::is_pythagorean_triplet(1U, 499U);
	EXPECT_FALSE(is_triplet);
}

TEST_NL(special_pythagorean_triplet, first_pair)
{
	EXPECT_EQ(Special_Pythagorean_Triplet::Naive(12U), 60U);
}

TEST_NL(special_pythagorean_triplet, answer)
{
	EXPECT_EQ(Special_Pythagorean_Triplet::Naive(1000U), Special_Pythagorean_Triplet::Optimized(1000U));
}
