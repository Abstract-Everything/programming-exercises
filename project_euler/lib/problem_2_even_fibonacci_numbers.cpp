#include "problem_2_even_fibonacci_numbers.hpp"

#include <utility>

namespace project_euler
{
	/**
	 * A brute force approach that manually calculates all finonacci numbers
	 * under the given upper bound and accumulates the even terms
	 */
	std::size_t accumulate_even_fibonacci(std::size_t upper_bound)
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
}
