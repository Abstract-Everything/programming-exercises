/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 9
 *
 * Find three integers a, b, c satisfying the following statements
 *
 * a * a + b * b = c * c
 *
 * a + b + c = 1000
 */

#include <cstddef>
#include <tuple>

namespace project_euler
{
	class Special_Pythagorean_Triplet
	{
	public:
		static constexpr const char* name = "Special pythagorean triplet";

		static std::pair<bool, std::size_t> is_pythagorean_triplet(std::size_t a, std::size_t b);

		/**
		 * @brief
		 * Finds a pythagorean triplet 
		 * a * a + b * b = c * c where a + b + c = sum
		 *
		 * This is done by going through all of the numbers from 1 to
		 * sum checking for triplets and if the sum matches.
		 */
		static std::size_t Naive(std::size_t sum);

		/**
		 * @brief
		 *
		 * This is done by going through all of the numbers checking
		 * if b is an integer for a given a:
		 *
		 * b = (sum - 2 * a) / (2 * ( 1 - a / sum))
		 *
		 * This can be obtained by the two required equations
		 *
		 * a * a + b * b = c * c
		 * a + b + c = sum
		 */
		static std::size_t Optimized(std::size_t sum);
	};
}
