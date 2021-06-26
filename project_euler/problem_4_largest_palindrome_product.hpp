#ifndef PROBLEM_4_LARGEST_PALINDROME_PRODUCT_HPP
#define PROBLEM_4_LARGEST_PALINDROME_PRODUCT_HPP

#include <vector>

namespace project_euler
{
	std::vector<unsigned int> split_decimal(unsigned int number);
	bool is_palindrome(unsigned int number);
	unsigned int largest_palindrome_product(unsigned int upper_bound);
}

#endif
