#include <project_euler/problem_1_multiples_of_3_and_5.hpp>
#include <project_euler/problem_2_even_fibonacci_numbers.hpp>
#include <project_euler/problem_3_largest_prime_factor.hpp>
#include <project_euler/problem_4_largest_palindrome_product.hpp>
#include <project_euler/problem_5_smallest_multiple.hpp>

#include <iostream>

using namespace project_euler;

int main()
{
	std::cout << "----- Answers -----" << "\n"
		  << "Problem 1: " << sum_multiples_of_3_5(1000) << "\n"
		  << "Problem 2: " << accumulate_even_fibonacci(4'000'000) << "\n"
		  << "Problem 3: " << largest_prime_factor(600'851'475'143) << "\n"
		  << "Problem 4: " << largest_palindrome_product(999) << "\n"
		  << "Problem 5: " << smallest_multiple(20) << "\n";
}
