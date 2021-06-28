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
