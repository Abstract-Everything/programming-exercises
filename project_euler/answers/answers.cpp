#include <project_euler/problem_1_multiples_of_3_and_5.hpp>
#include <project_euler/problem_2_even_fibonacci_numbers.hpp>
#include <project_euler/problem_3_largest_prime_factor.hpp>
#include <project_euler/problem_4_largest_palindrome_product.hpp>
#include <project_euler/problem_5_smallest_multiple.hpp>
#include <project_euler/problem_6_sum_square_difference.hpp>
#include <project_euler/problem_7_ten_thousand_and_first_prime.hpp>
#include <project_euler/problem_8_largest_product_in_a_series.hpp>

#include <iostream>
#include <chrono>

using namespace project_euler;

template<typename Func, typename... Arguments>
std::size_t time_problem(Func function, Arguments&&... arguments)
{
	const std::size_t iterations = 500000;
	std::size_t total = 0;
	for (std::size_t i = 0; i < iterations; ++i)
	{
		auto start = std::chrono::steady_clock::now();
		function(std::forward<Arguments>(arguments)...);
		auto end = std::chrono::steady_clock::now();
		total += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	}
	return total / iterations;
}

template<typename Problem, typename... Arguments>
void print_problem(Arguments&&... arguments)
{
	std::cout << "Problem Name: " << Problem::name << "\n"
		<< "\t" << "Answer: " << Problem::Optimized(std::forward<Arguments>(arguments)...) << "\n"
		<< "\t" << "Naive Timing: " << time_problem(Problem::Naive, std::forward<Arguments>(arguments)...) << "ns" << "\n"
		<< "\t" << "Optimized Timing: " << time_problem(Problem::Optimized, std::forward<Arguments>(arguments)...) << "ns" << "\n";
}

int main()
{
	std::cout << "----- Answers -----" << "\n";
	print_problem<Sum_Multiples_Of_3_And_5>(999);
	print_problem<Even_Fibonacci_Numbers>(4'000'000);
	std::cout
		<< "Problem 3: " << largest_prime_factor(600'851'475'143) << "\n"
		<< "Problem 4: " << largest_palindrome_product(999) << "\n"
		<< "Problem 5: " << smallest_multiple(20) << "\n"
		<< "Problem 6: " << sum_square_difference(100U) << "\n"
		<< "Problem 7: " << ten_thousand_and_first_prime() << "\n"
		<< "Problem 8: " << largest_product_in_a_series(problem_string, 13U) << "\n";
}
