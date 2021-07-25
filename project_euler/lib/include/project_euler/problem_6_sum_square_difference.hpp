/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 6
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#ifndef PROJECT_EULER_PROBLEM_6_SUM_SQUARE_DIFFERENCE_HPP
#define PROJECT_EULER_PROBLEM_6_SUM_SQUARE_DIFFERENCE_HPP

#include <cstddef>

namespace project_euler
{
	class Sum_Square_Difference
	{
	public:
		static constexpr const char* name = "Sum square difference";

		/**
		 * @brief
		 * Finds the difference between the square of the sum and the sum of squares
		 */
		static std::size_t Naive(std::size_t upper_bound);

		/**
		 * @brief
		 * Finds the difference between the square of the sum and the sum of squares
		 * in linear time
		 */
		static std::size_t Optimized(std::size_t upper_bound);
	};
}

#endif
