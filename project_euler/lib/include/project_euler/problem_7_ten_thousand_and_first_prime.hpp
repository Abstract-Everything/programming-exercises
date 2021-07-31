/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 7
 *
 * Find the 10 001st prime number?
 */

#ifndef PROJECT_EULER_PROBLEM_7_TEN_THOUSAND_AND_FIRST_PRIME_HPP
#define PROJECT_EULER_PROBLEM_7_TEN_THOUSAND_AND_FIRST_PRIME_HPP

#include "common.hpp"

namespace project_euler
{
	class Ten_Thousand_And_First_Prime
	{
	public:
		static constexpr const char* name = "Ten thousand and first prime";

		/**
		 * Returns the ten thousand and first prime
		 */
		static std::size_t Naive();
	};
}

#endif
