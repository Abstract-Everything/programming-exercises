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

		while (number % 2 == 0)
		{
			number /= 2;
			primes.push_back(2);
		}

		std::size_t divisor = 3;
		while (number > 1)
		{
			if (number % divisor == 0)
			{
				number /= divisor;
				primes.push_back(divisor);
			}
			else
			{
				divisor += 2;
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
		for (std::size_t i = 3; primes.size() < number_of_primes; i += 2U)
		{

			const bool is_prime = std::all_of(
					primes.begin(),
					primes.end(),
					[i](std::size_t prime) { return i % prime != 0; });

			if (is_prime)
			{
				primes.push_back(i);
			}
		}
		return primes;
	}

	std::vector<std::size_t> primes_under_ten(std::size_t upper_bound)
	{
		switch (upper_bound)
		{
			case 0:
			case 1:
				return {};

			case 2:
				return { 2U };

			case 3:
			case 4:
				return { 2U, 3U };

			case 5:
			case 6:
				return { 2U, 3U, 5U };

			case 7:
			case 8:
			case 9:
			case 10:
				return { 2U, 3U, 5U, 7U };
		}
		assert(upper_bound <= 10 && "Expected a number equal to or under 10");
		return {};
	}

	void disable_flags(std::vector<bool>& prime_flags, std::size_t prime)
	{
		for (std::size_t multiple = prime * prime; multiple < prime_flags.size(); multiple += 2 * prime)
		{
			prime_flags[multiple] = false;
		}
        }

	/*
	 * Finds prime numbers using the sieve of eratosthenes
	 */
	std::vector<std::size_t> primes_under(std::size_t upper_bound)
	{
		if (upper_bound < 11U)
		{
			return primes_under_ten(upper_bound);
		}

		std::vector<bool> prime_flags(upper_bound + 1, true);
		std::vector<std::size_t> primes = primes_under_ten(10U);
		disable_flags(prime_flags, 3U);
		disable_flags(prime_flags, 7U);

		const auto check_prime = [&prime_flags, &primes, upper_bound](std::size_t multiple)
		{
			if (prime_flags[multiple])
			{
				primes.push_back(multiple);
				disable_flags(prime_flags, multiple);
			}
		};

		for (std::size_t i = 10; i < upper_bound; i += 10)
		{
			check_prime(i + 1);
			check_prime(i + 3);
			check_prime(i + 7);
			check_prime(i + 9);
		}

		while(primes.back() > upper_bound)
		{
			primes.pop_back();
		}

		return primes;
	}
}// namespace project_euler
