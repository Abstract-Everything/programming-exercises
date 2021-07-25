#include "problem_4_largest_palindrome_product.hpp"

#include <cmath>
#include <string>

namespace project_euler
{
	/*
	 * A brute force methods which checks all the possible products for a palindrome.
	 * The loops check the numbers diagonally (right to left) to ensure that the largest number is tried first.
	 * E.g for a product of 99
	 *
	 * Numbers	99		98		97		96		...
	 * 99		99 * 99		-------		-------		-------		
	 * 98		98 * 99		98 * 98		-------		-------
	 * 97		97 * 99		97 * 98		97 * 97		-------
	 * 96		96 * 99		96 * 98		96 * 97		96 * 96
	 *
	 * The '-------' are skipped because the table is symettric
	 * The loops check:
	 * 99 * 99
	 * 98 * 99
	 * 98 * 98
	 * 97 * 99
	 * 97 * 98
	 * 96 * 99
	 * 97 * 97
	 * ..
	 * ..
	 */
	std::size_t Largest_Palindrome_Product::Naive(std::size_t upper_bound)
	{
		for (std::size_t diagonal = upper_bound; diagonal > 0; --diagonal)
		{
			std::size_t product_a = diagonal;
			for (std::size_t product_b = product_a; product_b < upper_bound && product_a > 0; ++product_b, --product_a)
			{
				const std::size_t product = product_a * product_b;
				if (is_palindrome(product))
				{
					return product;
				}
			}
		}

		return 0U;
	}

	bool Largest_Palindrome_Product::is_palindrome(std::size_t number)
	{
		std::string digits = std::to_string(number);
		for (std::size_t front_index = 0; front_index < digits.size() / 2; ++front_index)
		{
			const std::size_t back_index = digits.size() - 1 - front_index;
			if(digits[front_index] != digits[back_index])
			{
				return false;
			}
		}
		return true;
	}
}
