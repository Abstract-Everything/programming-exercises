#ifndef PROJECT_EULER_COMMON_HPP
#define PROJECT_EULER_COMMON_HPP

#include <vector>

namespace project_euler
{
	template<typename T>
	constexpr T linear_sum(T max)
	{
		return max * (max + 1) / 2;
	}

	template<typename T>
	constexpr T squared_sum(T max)
	{
		return max * (max + 1) * (2 * max + 1) / 6;
	}

	std::vector<std::size_t> prime_factorization(std::size_t number);
}

#endif
