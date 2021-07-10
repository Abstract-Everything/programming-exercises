#include "problem_4_largest_palindrome_product.hpp"

#include <cmath>

namespace project_euler
{
	std::vector<unsigned int> split_decimal(unsigned int number)
	{
		if (number == 0U)
		{
			return {number};
		}

		std::vector<unsigned int> digits;
		while(number)
		{
			digits.push_back(number % 10);
			number /= 10U;
		}
		return digits;
	}

	bool is_palindrome(unsigned int number)
	{
		std::vector<unsigned int> digits = split_decimal(number);
		for (unsigned int digit_to_check = 0; digit_to_check < digits.size(); ++digit_to_check)
		{
			const unsigned int opposite_digit = digits.size() - 1 - digit_to_check;
			if (opposite_digit <= digit_to_check)
			{
				break;
			}
			
			if (digits[digit_to_check] != digits[opposite_digit])
			{
				return false;
			}
		}
		return true;
	}

	unsigned int largest_palindrome_product(unsigned int upper_bound)
	{
		for (unsigned int diagonal = upper_bound - 1; diagonal > 0; --diagonal)
		{
			unsigned int product_a = diagonal;
			for (unsigned int product_b = product_a; product_b < upper_bound && product_a > 0; ++product_b, --product_a)
			{
				const unsigned int product = product_a * product_b;
				if (is_palindrome(product))
				{
					return product;
				}
			}
		}

		return 0U;
	}
}
