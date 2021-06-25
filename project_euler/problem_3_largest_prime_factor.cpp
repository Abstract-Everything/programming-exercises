#include "problem_3_largest_prime_factor.hpp"

namespace project_euler
{
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
}
