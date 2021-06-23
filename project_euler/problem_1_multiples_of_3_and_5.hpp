#ifndef PROBLEM_1_MULTIPLES_OF_3_AND_5_HPP
#define PROBLEM_1_MULTIPLES_OF_3_AND_5_HPP

#include <cmath>

namespace project_euler
{
	constexpr unsigned int multiple_upper_bound(unsigned int upper_bound, unsigned int multiple)
	{
		return std::llround(upper_bound / multiple);
	}

	constexpr unsigned int sum_from_zero(unsigned int upper_bound)
	{
		return upper_bound * (upper_bound + 1) / 2;
	}

	constexpr unsigned int sum_multiples_of_3_5(unsigned int upper_bound)
	{
		unsigned int sum_3 = 3 * sum_from_zero(multiple_upper_bound(upper_bound, 3));
		unsigned int sum_5 = 5 * sum_from_zero(multiple_upper_bound(upper_bound, 5));
		unsigned int sum_15 = 15 * sum_from_zero(multiple_upper_bound(upper_bound, 15));
		return sum_3 + sum_5 - sum_15;
	}
}

#endif