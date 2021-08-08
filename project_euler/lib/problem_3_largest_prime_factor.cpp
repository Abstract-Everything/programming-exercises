#include "problem_3_largest_prime_factor.hpp"

#include "common.hpp"

namespace project_euler
{
	std::size_t Largest_Prime_Factor::Naive(std::size_t number)
	{
		return prime_factorization(number).rbegin()->first;
	}
}
