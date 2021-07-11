#include "problem_3_largest_prime_factor.hpp"

#include "common.hpp"

namespace project_euler
{
	std::size_t largest_prime_factor(std::size_t number)
	{
		return prime_factorization(number).back();
	}
}
