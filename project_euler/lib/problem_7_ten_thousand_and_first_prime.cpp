#include "problem_7_ten_thousand_and_first_prime.hpp"
#include "common.hpp"

#include <iostream>

namespace project_euler
{
	std::size_t Ten_Thousand_And_First_Prime::Naive()
	{
		return prime_list(10'001U).back();
	}
}
