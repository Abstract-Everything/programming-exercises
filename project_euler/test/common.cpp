#include <project_euler/common.hpp>

#include <gmock/gmock.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;
using namespace testing;

TEST_NL(largest_prime_factor, prime_factorize_two)
{
	auto primes = prime_factorization(2);
	ASSERT_THAT(primes, ElementsAre(2U));
}

TEST_NL(largest_prime_factor, prime_factorize_size)
{
	auto primes = prime_factorization(6);
	ASSERT_THAT(primes, ElementsAre(2U, 3U));
}

TEST_NL(largest_prime_factor, multiple_occuring_factor)
{
	auto primes = prime_factorization(8);
	ASSERT_THAT(primes, ElementsAre(2U, 2U, 2U));
}

TEST_NL(list_primes, no_primes)
{
	auto primes = prime_list(0);
	ASSERT_TRUE(primes.empty());
}

TEST_NL(list_primes, first_prime)
{
	auto primes = prime_list(2);
	ASSERT_THAT(primes, ElementsAre(2U, 3U));
}

TEST_NL(list_primes, up_five_primes)
{
	auto primes = prime_list(5);
	ASSERT_THAT(primes, ElementsAre(2U, 3U, 5U, 7U, 11U));
}

TEST_NL(primes_under, up_to_ten)
{
	auto primes = primes_under(10U);
	ASSERT_THAT(primes, ElementsAre(2U, 3U, 5U, 7U));
}

TEST_NL(primes_under, include_upper_bound)
{
	auto primes = primes_under(11U);
	ASSERT_THAT(primes, ElementsAre(2U, 3U, 5U, 7U, 11U));
}

TEST_NL(primes_under, first_100_primes)
{
	auto list = prime_list(100U);
	auto under = primes_under(list.back());
	EXPECT_EQ(list, under);
}
