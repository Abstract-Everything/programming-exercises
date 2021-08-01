#include <project_euler/problem_1_multiples_of_3_and_5.hpp>
#include <project_euler/problem_2_even_fibonacci_numbers.hpp>
#include <project_euler/problem_3_largest_prime_factor.hpp>
#include <project_euler/problem_4_largest_palindrome_product.hpp>
#include <project_euler/problem_5_smallest_multiple.hpp>
#include <project_euler/problem_6_sum_square_difference.hpp>
#include <project_euler/problem_7_ten_thousand_and_first_prime.hpp>
#include <project_euler/problem_8_largest_product_in_a_series.hpp>
#include <project_euler/problem_9_special_pythagorean_triplet.hpp>

#include <iostream>
#include <chrono>

using namespace project_euler;

#define DEFINE_HAS_MEMBER_T(Member) \
template<typename, typename = std::void_t<>> \
struct has_member_t_##Member \
: std::false_type { }; \
template<typename T> \
struct has_member_t_##Member<T, std::void_t<decltype(&T::Member)>> \
: std::true_type { };

template<typename Func, typename... Arguments>
std::size_t time_problem(Func function, Arguments&&... arguments)
{
	const std::size_t iterations = 50;
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

DEFINE_HAS_MEMBER_T(Optimized)

template<typename Problem, typename... Arguments, typename std::enable_if_t<has_member_t_Optimized<Problem>::value, bool> = true>
void print_optimized_timing(Arguments&&... arguments) 
{
	std::cout << "\t" << "Optimized Timing: " << time_problem(Problem::Optimized, std::forward<Arguments>(arguments)...) << "ns" << "\n";
}

template<typename Problem, typename... Arguments, typename std::enable_if_t<!has_member_t_Optimized<Problem>::value, bool> = true>
void print_optimized_timing(Arguments&&... arguments)
{
}

template<typename Problem, typename... Arguments>
void print_problem(Arguments&&... arguments)
{
	std::cout << "Problem Name: " << Problem::name << "\n"
		<< "\t" << "Answer: " << Problem::Naive(std::forward<Arguments>(arguments)...) << "\n"
		<< "\t" << "Naive Timing: " << time_problem(Problem::Naive, std::forward<Arguments>(arguments)...) << "ns" << "\n";
	print_optimized_timing<Problem>(std::forward<Arguments>(arguments)...);
	std::cout << "\n";
}

int main()
{
	std::cout << "----- Answers -----" << "\n";
	print_problem<Sum_Multiples_Of_3_And_5>(999);
	print_problem<Even_Fibonacci_Numbers>(4'000'000);
	print_problem<Largest_Prime_Factor>(600'851'475'143);
	print_problem<Largest_Palindrome_Product>(999);
	print_problem<Smallest_Multiple>(20);
	print_problem<Sum_Square_Difference>(100);
	print_problem<Ten_Thousand_And_First_Prime>();
	print_problem<Largest_Product_In_A_Series>(Largest_Product_In_A_Series::problem_string, 13U);
	print_problem<Special_Pythagorean_Triplet>(1000U);
}
