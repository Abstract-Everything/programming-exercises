if(NOT ${CPP_TMPL_TESTING} STREQUAL "gtest")
	return()
endif()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(
	project_euler_test
	common.cpp
	multiples_of_3_and_5_test.cpp
	even_fibonacci_numbers.cpp
	largest_palindrome_product.cpp
	smallest_multiple.cpp
	sum_square_difference.cpp
	largest_product_in_a_series.cpp
	special_pythagorean_triplet.cpp
	summation_of_primes.cpp
	largest_product_in_a_grid.cpp)

target_link_libraries(
	project_euler_test
	PRIVATE project_options
		project_warnings
		project_euler_lib
		GTest::gtest
		GTest::gtest_main)

gtest_discover_tests(project_euler_test)
