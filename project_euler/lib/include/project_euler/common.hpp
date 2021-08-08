/**
 * @file
 *
 * @section DESCRIPTION
 * A file for common utility functions.
 */

#ifndef PROJECT_EULER_COMMON_HPP
#define PROJECT_EULER_COMMON_HPP

#include <vector>
#include <cassert>
#include <type_traits>
#include <map>

namespace project_euler
{
	/**
	 * @brief
	 * Asserts that the given argument is a positive natural number
	 */
	template<typename T>
	constexpr void assert_natural_number(T number)
	{
		static_assert(std::is_integral<T>::value, "Expected a positive natural number.");
		assert(number >= 0 && "Expected a positive natural number.");
	}

	/**
	 * @brief
	 * Sums all natural numbers up to *number* in constant time
	 * 
	 * @param
	 * number The last term in the sequence of the sum
	 *
	 * @return
	 * The result of the sum 1 + 2 + .. + n
	 */
	template<typename T>
	constexpr T linear_sum(T number)
	{
		assert_natural_number(number);
		return number * (number + 1) / 2;
	}

	/**
	 * @brief
	 * Sums the square of all natural numbers up to *number* in constant time
	 * 
	 * @param
	 * number The last term in the sequence of the sum
	 *
	 * @return
	 * The result of the sum 1 * 1 + 2 * 2 + .. + n * n
	 */
	template<typename T>
	constexpr T squared_sum(T number)
	{
		assert_natural_number(number);
		return number * (number + 1) * (2 * number + 1) / 6;
	}

	using Prime_Count = std::map<std::size_t, std::size_t>;

	/**
	 * @brief
	 * Calculates the prime factors for a given number in O(n ^ (1/2)) worst case time
	 */
	Prime_Count prime_factorization(std::size_t number);

	/**
	 * @brief
	 * Computes an ordered list of primes in O(n * n / log n) time.
	 *
	 * @param
	 * number_of_primes The number of primes which should be calculated
	 */
	std::vector<std::size_t> prime_list(std::size_t number_of_primes);

	/**
	 * @brief
	 * Computes an ordered list of primes under a given value.
	 *
	 * @param
	 * upper_bound The prime searching limit
	 */
	std::vector<std::size_t> primes_under(std::size_t upper_bound);
}

#endif
