#ifndef PROJECT_EULER_PROBLEM_1_MULTIPLES_OF_3_AND_5_HPP
#define PROJECT_EULER_PROBLEM_1_MULTIPLES_OF_3_AND_5_HPP

#include "common.hpp"

#include <cmath>

namespace project_euler
{
	constexpr unsigned int multiple_upper_bound(unsigned int upper_bound, unsigned int multiple)
	{
		return std::llround(upper_bound / multiple);
	}

	constexpr unsigned int sum_multiples_of_3_5(unsigned int upper_bound)
	{
		unsigned int sum_3 = 3 * linear_sum(multiple_upper_bound(upper_bound, 3));
		unsigned int sum_5 = 5 * linear_sum(multiple_upper_bound(upper_bound, 5));
		unsigned int sum_15 = 15 * linear_sum(multiple_upper_bound(upper_bound, 15));
		return sum_3 + sum_5 - sum_15;
	}
}

#endif
