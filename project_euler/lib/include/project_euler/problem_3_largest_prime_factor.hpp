/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 3
 *
 * Find the largest prime factor under 600851475143
 */

#ifndef PROJECT_EULER_PROBLEM_3_LARGEST_PRIME_FACTOR_HPP
#define PROJECT_EULER_PROBLEM_3_LARGEST_PRIME_FACTOR_HPP

#include <cstddef>

namespace project_euler
{
	class Largest_Prime_Factor
	{
	public:
		static constexpr const char* name = "Largest prime factor";

		/**
		 * @brief
		 * Returns the largest prime factor for a given number
		 */
                static std::size_t Naive(std::size_t number);
        };
}

#endif
