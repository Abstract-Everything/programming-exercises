/**
 * @file
 *
 * @section DESCRIPTION
 * Solution to Problem 10
 *
 * Find the sum of all primes below two million
 */

#include <cstddef>

namespace project_euler
{
	class Summation_Of_Primes
	{
	public:
		static constexpr const char* name = "Summation of primes";

		static std::size_t Naive(std::size_t upper_bound);
	};
}
