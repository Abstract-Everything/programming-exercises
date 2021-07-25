#include "problem_5_smallest_multiple.hpp"

#include "common.hpp"

#include <map>
#include <algorithm>
#include <cmath>

namespace project_euler
{
	/*
	 * The smallest multiple divisible by all natrual numbers below number
	 * is equal to the product of primes needed for each number to be able
	 * to divide the number.
	 *
	 * E.g. the smallest multiple divisible by all numbers below or equal to 10:
	 * 2  = 2
	 * 3  = 3
	 * 4  = 2 * 2
	 * 5  = 5
	 * 6  = 2 * 3
	 * 7  = 7		<- maximum 7s
	 * 8  = 2 * 2 * 2	<- maximum 2s
	 * 9  = 3 * 3		<- maximum 3s
	 * 10 = 2 * 5		<- maximum 5s
	 *
	 * product = (2 * 2 * 2) * (3 * 3) * (5) * (7) = 2520
	 */
	std::size_t Smallest_Multiple::Naive(std::size_t number)
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
