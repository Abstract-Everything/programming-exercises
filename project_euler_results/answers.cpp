#include <project_euler/problem_1_multiples_of_3_and_5.hpp>
#include <project_euler/problem_2_even_fibonacci_numbers.hpp>

#include <iostream>

using namespace project_euler;

int main()
{
	std::cout << "----- Answers -----" << "\n"
		  << "Problem 1: " << sum_multiples_of_3_5(1000) << "\n"
		  << "Problem 2: " << accumulate_even_fibonacci(4'000'000) << "\n";
}
