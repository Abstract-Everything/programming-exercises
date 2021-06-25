#include <project_euler/problem_1_multiples_of_3_and_5.hpp>
#include <project_euler/problem_2_even_fibonacci_numbers.hpp>
#include <project_euler/problem_3_largest_prime_factor.hpp>

#include <iostream>

using namespace project_euler;

int main()
{
	std::cout << "----- Answers -----" << "\n"
		  << "Problem 1: " << sum_multiples_of_3_5(1000) << "\n"
		  << "Problem 2: " << accumulate_even_fibonacci(4'000'000) << "\n"
		  << "Problem 3: " << prime_factorization(600'851'475'143).back() << "\n";
}
