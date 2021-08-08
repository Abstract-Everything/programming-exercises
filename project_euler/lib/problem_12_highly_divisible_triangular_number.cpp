#include "problem_12_highly_divisible_triangular_number.hpp"

#include "common.hpp"

#include <algorithm>
#include <cstdlib>
#include <limits>

namespace project_euler
{
	std::size_t Highly_Divisible_Triangular_Number::Naive(std::size_t number_of_divisors)
	{
		for (std::size_t number = 1;
			number < std::numeric_limits<std::size_t>::max();
			++number)
		{
			std::size_t triangular_number = linear_sum(number);
			std::size_t factor_count = number_of_factors(triangular_number);
			if (factor_count >= number_of_divisors)
			{
				return triangular_number;
			}
		}

		return 0;
	}

	/**
	 * All possible factors are the permutations of the primes that factor
	 * the number. This procedure gets the prime factorization of the number
	 * and counts the permutations of the primes.
	 *
	 * For example for the number 36:
	 * prime factorization = 2, 2, 3, 3
	 *
	 * Thus all factors are:
	 * permutations of 2s and 3s:
	 * 1 * permutations of 3s,
	 * 2 * permutation of 3s,
	 * 2 * 2 * permutation of 3s
	 *
	 * permutation of 3s:
	 * 1,
	 * 3,
	 * 3 * 3
	 *
	 * Thus the factors are:
	 * 1 * 1,     1 * 3,     1 * 3 * 3
	 * 2 * 1,     2 * 3,     2 * 3 * 3
	 * 2 * 2 * 1, 2 * 2 * 3, 2 * 2 * 3 * 3
	 *
	 */
	std::size_t Highly_Divisible_Triangular_Number::number_of_factors(std::size_t number)
	{
		auto prime_factors = prime_factorization(number);
		std::size_t factor_count = 1;
		for (auto pair : prime_factors)
		{
			factor_count *= pair.second + 1;
		}

		return factor_count;
	}
}
