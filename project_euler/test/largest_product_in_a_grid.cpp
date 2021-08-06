#include <project_euler/problem_11_largest_product_in_a_grid.hpp>

#include <gmock/gmock.h>
#define TEST_NL(test_suite_name, test_name) TEST(test_suite_name, test_name) // NOLINT

using namespace project_euler;
using namespace testing;

TEST_NL(read_grid, single_number)
{
	auto grid = Largest_Product_In_A_Grid::read_grid("01");
	ASSERT_THAT(grid, ElementsAre(std::vector<std::size_t>{1}));
}

TEST_NL(read_grid, multiple_numbers)
{
	auto grid = Largest_Product_In_A_Grid::read_grid("01 02 3 4 05");
	ASSERT_THAT(grid, ElementsAre(
		std::vector<std::size_t>{1, 2, 3, 4, 5}
	));
}

TEST_NL(read_grid, multiple_lines)
{
	auto grid = Largest_Product_In_A_Grid::read_grid(
			"01 02 03 04 05\n"
			"06 07 08 09 10\n"
			"11 12 13 14 15\n"
			);
	ASSERT_THAT(grid, ElementsAre(
		std::vector<std::size_t>{1, 2, 3, 4, 5},
		std::vector<std::size_t>{6, 7, 8, 9, 10},
		std::vector<std::size_t>{11, 12, 13, 14, 15}
	));
}

TEST_NL(read_grid, multiple_lines_mismatching_sizes)
{
	auto grid = Largest_Product_In_A_Grid::read_grid(
			"01 02 03 04 05\n"
			"06 07 08 09\n"
			"11 12 13 14 15\n"
			);
	ASSERT_TRUE(grid.size() == 0);
}

TEST_NL(largest_product_in_a_grid, two_by_two_horizontal)
{
	auto result = Largest_Product_In_A_Grid::Naive(
			"1 2\n"
			"3 4\n",
			2
		);
	ASSERT_EQ(result, 12U);
}

TEST_NL(largest_product_in_a_grid, two_by_two_vertical)
{
	auto result = Largest_Product_In_A_Grid::Naive(
			"5 2\n"
			"3 2\n",
			2
		);
	ASSERT_EQ(result, 15U);
}

TEST_NL(largest_product_in_a_grid, two_by_two_diagonal)
{
	auto result = Largest_Product_In_A_Grid::Naive(
			"5 2\n"
			"3 5\n",
			2
		);
	ASSERT_EQ(result, 25U);
}

TEST_NL(largest_product_in_a_grid, more_digits_than_grid_size)
{
	auto result = Largest_Product_In_A_Grid::Naive(
			"5 2\n"
			"3 5\n",
			3
		);
	ASSERT_EQ(result, 0U);
}

TEST_NL(largest_product_in_a_grid, multiple_digits)
{
	std::string grid = 
			"02 01 03 01\n"
			"01 02 01 01\n"
			"01 01 02 01\n"
			"01 01 03 01\n";

	auto result_three = Largest_Product_In_A_Grid::Naive(grid, 3);
	ASSERT_EQ(result_three, 8U);
	auto result_four = Largest_Product_In_A_Grid::Naive(grid, 4);
	ASSERT_EQ(result_four, 18U);
}
