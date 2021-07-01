#include "problem_7_ten_thousand_and_first_prime.hpp"
#include "common.hpp"

#include <iostream>

namespace project_euler
{
	std::size_t ten_thousand_and_first_prime()
	{
		return prime_list(10'001U).back();
	}
}
