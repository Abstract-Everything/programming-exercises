#include "problem_6_sum_square_difference.hpp"
#include "common.hpp"

namespace project_euler
{
	std::size_t Sum_Square_Difference::Naive(std::size_t upper_bound)
	{
		std::size_t sum_squared = 0;
		std::size_t squared_sum = 0;
		for (std::size_t i = 0; i <= upper_bound; ++i)
		{
			sum_squared += i * i;
			squared_sum += i;
		}
		squared_sum *= squared_sum;
		return squared_sum - sum_squared;
	}

	/**
	 * This can be achieved in constant time by the following formule
	 *
	 * 1 + 2 + 3 + .. + n = n (n + 1) / 2
	 * 1 * 1 + 2 * 2 + 3 * 3 + ... + n * n = n (n + 1) (2n + 1) / 6;
	 */
	std::size_t Sum_Square_Difference::Optimized(std::size_t upper_bound)
	{
		std::size_t linear = linear_sum(upper_bound);
		return linear * linear - squared_sum(upper_bound) ;
	}
}
