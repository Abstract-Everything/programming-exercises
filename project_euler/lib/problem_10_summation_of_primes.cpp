#include "problem_10_summation_of_primes.hpp"

#include "common.hpp"

#include <numeric>

namespace project_euler
{
	std::size_t Summation_Of_Primes::Naive(std::size_t upper_bound)
	{
		std::vector<std::size_t> primes = primes_under(upper_bound);
		return std::accumulate(primes.begin(), primes.end(), static_cast<std::size_t>(0U));
	}
}
