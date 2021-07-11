#include "problem_6_sum_square_difference.hpp"
#include "common.hpp"

namespace project_euler
{
	/**
	 * This can be achieved in constant time by the following formule
	 *
	 * 1 + 2 + 3 + .. + n = n (n + 1) / 2
	 * 1 * 1 + 2 * 2 + 3 * 3 + ... + n * n = n (n + 1) (2n + 1) / 6;
	 */
	unsigned int sum_square_difference(unsigned int upper_bound)
	{
		unsigned int linear = linear_sum(upper_bound);
		return linear * linear - squared_sum(upper_bound) ;
	}
}
