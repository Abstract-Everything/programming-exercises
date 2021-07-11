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
	/**
	 * @brief
	 * Calculates the sum of even fibonacci numbers up to a bound
	 */
	std::size_t accumulate_even_fibonacci(std::size_t upper_bound);
}

#endif
