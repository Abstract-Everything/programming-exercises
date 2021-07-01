#include "common.hpp"

#include <algorithm>

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

	std::vector<std::size_t> prime_list(std::size_t number_of_primes)
	{
		std::vector<std::size_t> primes{2U};
		for (std::size_t i = 3; primes.size() < number_of_primes; i += 2)
		{

			bool is_prime = std::all_of(primes.begin(), primes.end(),
					[i](std::size_t prime){ return i % prime != 0;});
			if (is_prime)
			{
				primes.push_back(i);
			}
		}
		return primes;
	}
}
