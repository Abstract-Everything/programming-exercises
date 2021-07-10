#include "problem_6_sum_square_difference.hpp"
#include "common.hpp"

namespace project_euler
{
	unsigned int sum_square_difference(unsigned int upper_bound)
	{
		unsigned int linear = linear_sum(upper_bound);
		return linear * linear - squared_sum(upper_bound) ;
	}
}
