#include "problem_2_even_fibonacci_numbers.hpp"

#include <utility>

namespace project_euler
{
	unsigned int accumulate_even_fibonacci(unsigned int upper_bound)
	{
		unsigned int first = 1;
		unsigned int sum_first = first;
		unsigned int sum_second = first;
		unsigned int sum_even = 0;
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
