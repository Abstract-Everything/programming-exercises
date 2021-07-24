#include "problem_1_multiples_of_3_and_5.hpp"

#include <cstddef>

namespace project_euler
{
	std::size_t Sum_Multiples_Of_3_And_5::Naive(std::size_t upper_bound)
	{
		std::size_t total = 0;
		for (std::size_t i = 0; i <= upper_bound; ++i)
		{
			if (i % 3 == 0 || i % 5 == 0)
			{
				total += i;
			}
		}
		return total;
	}

	std::size_t Sum_Multiples_Of_3_And_5::Optimized(std::size_t upper_bound)
	{
		std::size_t sum_3 = linear_sum_for_multiple(upper_bound, 3);
		std::size_t sum_5 = linear_sum_for_multiple(upper_bound, 5);
		std::size_t sum_15 = linear_sum_for_multiple(upper_bound, 15);
		return sum_3 + sum_5 - sum_15;
	}

	std::size_t Sum_Multiples_Of_3_And_5::linear_sum_for_multiple(std::size_t upper_bound, std::size_t multiple)
	{
		std::size_t multiple_upper_bound = std::llround(upper_bound / multiple);
		return multiple * linear_sum(multiple_upper_bound);
	}
}
