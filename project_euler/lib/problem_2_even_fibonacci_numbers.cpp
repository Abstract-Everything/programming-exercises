#include "problem_2_even_fibonacci_numbers.hpp"

#include <utility>
#include <cmath>

namespace project_euler
{
	/**
	 * A brute force approach that manually calculates all finonacci numbers
	 * under the given upper bound and accumulates the even terms
	 */
	std::size_t Even_Fibonacci_Numbers::Naive(std::size_t upper_bound)
	{
		std::size_t first = 1;
		std::size_t sum_first = first;
		std::size_t sum_second = first;
		std::size_t sum_even = 0;
		while (sum_second < upper_bound)
		{
			sum_first += sum_second;
			std::swap(sum_first, sum_second);
			if (sum_second % 2 == 0)
			{
				sum_even += sum_second;
			}
		}
		return sum_even;
	}

	/**
	 * The fibonacci numbers take a pattern of two odd numbers then an even
	 * This can be observed by keeping in mind that:
	 * odd + odd = even
	 * odd + even = odd
	 *
	 * The pattern starts with 1, 1 which are both odd, thus the next term
	 * must be even. Now the last two terms are even and odd so the sum is
	 * odd. Now we end up where we started with two odd numbers. Thus every
	 * third number we have an even.
	 *
	 * This optimization removes the remainder operation which was by far
	 * the most expensive.
	 */
	std::size_t Even_Fibonacci_Numbers::Optimized(std::size_t upper_bound)
	{
		std::size_t sum_first = 1;
		std::size_t sum_second = 2;
		std::size_t sum_even = 0;
		while (sum_second < upper_bound)
		{
			sum_even += sum_second;
			sum_first += sum_second;
			sum_second += sum_first;
			sum_first += sum_second;
			std::swap(sum_first, sum_second);
		}
		return sum_even;
	}
}
