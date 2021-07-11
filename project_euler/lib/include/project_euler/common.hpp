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

	/**
	 * @brief
	 * Calculates the prime factors for a given number in O(n ^ (1/2)) worst case time
	 */
	std::vector<std::size_t> prime_factorization(std::size_t number);

	/**
	 * @brief
	 * Computes an ordered list of primes in O(n * n / log n) time.
	 *
	 * @param
	 * number_of_primes The number of primes which should be calculated
	 */
	std::vector<std::size_t> prime_list(std::size_t number_of_primes);
}

#endif
