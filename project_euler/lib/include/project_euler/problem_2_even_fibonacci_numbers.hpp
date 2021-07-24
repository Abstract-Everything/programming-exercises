/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 2
 *
 * Find the sum of even valued finonacci up to 4 million
 */

#ifndef PROJECT_EULER_PROBLEM_2_EVEN_FIBONACCI_NUMBERS_HPP
#define PROJECT_EULER_PROBLEM_2_EVEN_FIBONACCI_NUMBERS_HPP

#include <cstddef>

namespace project_euler
{
	class Even_Fibonacci_Numbers
	{
	public:
		static constexpr const char* name = "Accumulate even fibonacci numbers";

		/**
		 * @brief
		 * Calculates the sum of even fibonacci numbers up to a bound
		 */
		static std::size_t Naive(std::size_t upper_bound);

		/**
		 * @brief
		 * Calculates the sum using a brute force approach like the
		 * Naive method but with observation that every third fibonacci
		 * number is an even number
		 */
		static std::size_t Optimized(std::size_t upper_bound);
	};
}

#endif
