/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 12
 *
 * Find the first triangle number with over 500 divisors
 */

#ifndef PROJECT_EULER_PROBLEM_12_HIGHLY_DIVISIBLE_TRIANGULAR_NUMBER_HPP
#define PROJECT_EULER_PROBLEM_12_HIGHLY_DIVISIBLE_TRIANGULAR_NUMBER_HPP

#include <cstddef>

namespace project_euler
{
	class Highly_Divisible_Triangular_Number
	{
	public:

		static constexpr const char* name = "highly divisible triangular number";

		/**
		 * @brief
		 * Uses brute force to check every triangular number.
		 */
		static std::size_t Naive(std::size_t number_of_divisors);

		/**
		 * @brief
		 * Finds the number of divisors that the given number has.
		 */
		static std::size_t number_of_factors(std::size_t number);
	};
}

#endif
