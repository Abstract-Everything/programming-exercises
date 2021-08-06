add_library(project_euler_lib STATIC
	common.cpp
	problem_1_multiples_of_3_and_5.cpp
	problem_2_even_fibonacci_numbers.cpp
	problem_3_largest_prime_factor.cpp
	problem_4_largest_palindrome_product.cpp
	problem_5_smallest_multiple.cpp
	problem_6_sum_square_difference.cpp
	problem_7_ten_thousand_and_first_prime.cpp
	problem_8_largest_product_in_a_series.cpp
	problem_9_special_pythagorean_triplet.cpp
	problem_10_summation_of_primes.cpp
	problem_11_largest_product_in_a_grid.cpp)

target_include_directories(
	project_euler_lib
	INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include/"
	PRIVATE "${CMAKE_CURRENT_LIST_DIR}/include/project_euler")

target_link_libraries(
	project_euler_lib
	PRIVATE project_options project_warnings)
