#include "common.hpp"

#include <algorithm>

namespace project_euler
{
	/**
	 * This is a brute force factorization function where all primes
	 * are tried starting from the lowest going up.
	 */
	std::vector<std::size_t> prime_factorization(std::size_t number)
	{
		std::vector<std::size_t> primes;

		std::size_t divisor = 2;
		while (number > 1)
		{
			if (number % divisor == 0)
			{
				number /= divisor;
				primes.push_back(divisor);
			}
			else
			{
				divisor++;
			}
		}
		return primes;
	}

	/**
	 * This is a Brute force function that goes through all of the numbers
	 * and checks if the new number is prime by keeping a list of previously
	 * encountered primes and finding a divisor
	 */
	std::vector<std::size_t> prime_list(std::size_t number_of_primes)
	{
		if (number_of_primes == 0)
		{
			return {};
		}

		std::vector<std::size_t> primes{ 2U };
		for (std::size_t i = 3; primes.size() < number_of_primes; i += 2)
		{

			const bool is_prime = std::all_of(primes.begin(), primes.end(), [i](std::size_t prime) { return i % prime != 0; });
			if (is_prime)
			{
				primes.push_back(i);
			}
		}
		return primes;
	}
}// namespace project_euler
