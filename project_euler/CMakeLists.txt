add_library(project_euler STATIC
	project_euler.cpp
	common.cpp
	problem_2_even_fibonacci_numbers.cpp
	problem_3_largest_prime_factor.cpp
	problem_4_largest_palindrome_product.cpp
	problem_5_smallest_multiple.cpp
	problem_6_sum_square_difference.cpp)

target_include_directories(
	project_euler
	INTERFACE "${CMAKE_CURRENT_LIST_DIR}/../"
	PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(
	project_euler
	PRIVATE project_options project_warnings)
