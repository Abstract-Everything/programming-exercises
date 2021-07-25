/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 5
 *
 * Smallest positive number evenly divisible by all natural numbers below 20
 */

#ifndef PROJECT_EULER_PROBLEM_5_SMALLEST_MULTIPLE_HPP
#define PROJECT_EULER_PROBLEM_5_SMALLEST_MULTIPLE_HPP

#include <cstddef>

namespace project_euler
{
	class Smallest_Multiple
	{
	public:
		static constexpr const char* name = "Smallest multiple";

		/*
		 * @brief
		 * Finds the smallest multiple divisible by all numbers below number
		 */
		static std::size_t Naive(std::size_t number);
	};
}

#endif
