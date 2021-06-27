#include "problem_5_smallest_multiple.hpp"
#include "problem_3_largest_prime_factor.hpp"

#include <map>
#include <algorithm>
#include <cmath>

namespace project_euler
{
	std::size_t smallest_multiple(std::size_t number)
	{
		std::map<std::size_t, std::size_t> aggregate_primes;
		for (std::size_t i = 2U; i <= number; ++i)
		{
			std::vector<std::size_t> primes = prime_factorization(i);
			for (auto prime : primes)
			{
				std::size_t count = std::count(primes.begin(), primes.end(), prime);
				aggregate_primes[prime] = std::max(aggregate_primes[prime], count);
			}
		}

		size_t multiple = 1;
		for (auto pair : aggregate_primes)
		{
			multiple *= static_cast<size_t>(std::pow(pair.first, pair.second));
		}
		return multiple;
	}
}
