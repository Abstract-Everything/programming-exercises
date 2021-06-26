if(NOT ${CPP_TMPL_TESTING} STREQUAL "gtest")
	return()
endif()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(
	project_euler_test
	${CMAKE_CURRENT_LIST_DIR}/multiples_of_3_and_5_test.cpp
	${CMAKE_CURRENT_LIST_DIR}/even_fibonacci_numbers.cpp
	${CMAKE_CURRENT_LIST_DIR}/largest_prime_factor.cpp
	${CMAKE_CURRENT_LIST_DIR}/largest_palindrome_product)

target_link_libraries(
	project_euler_test
	PRIVATE project_options
		project_warnings
		project_euler
		GTest::gtest
		GTest::gtest_main)

gtest_discover_tests(project_euler_test)
