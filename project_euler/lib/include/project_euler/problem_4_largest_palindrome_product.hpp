/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 4
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#ifndef PROJECT_EULER_PROBLEM_4_LARGEST_PALINDROME_PRODUCT_HPP
#define PROJECT_EULER_PROBLEM_4_LARGEST_PALINDROME_PRODUCT_HPP

#include <vector>
#include <cstddef>

namespace project_euler
{
	class Largest_Palindrome_Product
	{
	public:
		constexpr static const char* name = "Largest palindrome number";

		/**
		 * @brief
		 * Finds the largest palindrome product of two numbers under a bound
		 *
		 * @param
		 * upper_bound The maximum number to search is upper_bound * upper_bound
		 */
		static std::size_t Naive(std::size_t upper_bound);

		/**
		 * @brief
		 * Checks if a number is identical if read backwards
		 */
		static bool is_palindrome(std::size_t number);
	};
}

#endif
