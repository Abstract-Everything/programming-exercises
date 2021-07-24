/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 1
 *
 * Find the sum of the multiples of 3 and 5 for numbers under 1000
 */

#ifndef PROJECT_EULER_PROBLEM_1_MULTIPLES_OF_3_AND_5_HPP
#define PROJECT_EULER_PROBLEM_1_MULTIPLES_OF_3_AND_5_HPP

#include "common.hpp"

#include <cmath>

namespace project_euler
{
	class Sum_Multiples_Of_3_And_5
	{
	public:

		static constexpr const char* name = "Sum multiples of 3 and 5";

		/**
		 * @brief
		 * Finds the sum of multiples of 3 and 5 under an upper_bound
		 *
		 * This is a brute for method which goes through all of the
		 * numbers up to an upper bound and check if each is a multiple.
		 */
		static std::size_t Naive(std::size_t upper_bound);

		/**
		 * @brief
		 * Finds the sum of multiples of 3 and 5 under an upper_bound
		 *
		 * This could be done in constant time by observing that for e.g. 1000
		 *
		 * The sum of 3s is: 3 + 6 + .. + 999 = 3 * (1 + 2 + .. + 333).
		 * The sum of 5s is: 5 + 10 + .. + 995 = 5 * (1 + 2 + .. + 199).
		 * Then the sum of 15s needs to be subtracted since it was added twice.
		 *
		 * Using the equation 1 + 2 + 3 + .. + n = n (n + 1) / 2 we can
		 * obtain the answer in constant time.
		 */
		static std::size_t Optimized(std::size_t upper_bound);

	private:
		/**
		 * @brief
		 * Finds the sum of all multiple under an upper_bound
		 */
		static std::size_t linear_sum_for_multiple(std::size_t upper_bound, std::size_t multiple);
	};
}

#endif
