#include "problem_11_largest_product_in_a_grid.hpp"

#include <sstream>

namespace project_euler
{
	std::size_t Largest_Product_In_A_Grid::Naive(
			const std::string& grid_string,
			std::size_t adjacent_digits)
	{
		Grid grid = read_grid(grid_string);
		std::size_t max = 0;
		for (std::size_t i = 0; i < grid.size(); ++i)
		{
			for (std::size_t j = 0; j < grid[i].size(); ++j)
			{
				max = std::max(max, horizontal_multiply(grid, adjacent_digits, i, j));
				max = std::max(max, vertical_multiply(grid, adjacent_digits, i, j));
				max = std::max(max, downward_multiply(grid, adjacent_digits, i, j));
				max = std::max(max, upward_multiply(grid, adjacent_digits, i, j));
			}
		}
		return max;
	}

	Largest_Product_In_A_Grid::Grid Largest_Product_In_A_Grid::read_grid(const std::string& grid_string)
	{
		Grid grid;
		std::istringstream grid_stream(grid_string);
		std::string line;
		while (getline(grid_stream, line))
		{
			grid.push_back({});

			std::istringstream line_stream(line);
			std::size_t number = 0;
			while (line_stream >> number)
			{
				grid.back().push_back(number);
			}

			if (grid.back().size() != grid[0].size())
			{
				return {};
			}
		}
		return grid;		
	}

	std::size_t Largest_Product_In_A_Grid::horizontal_multiply(
		const Grid& grid,
		std::size_t adjacent_digits,
		std::size_t i,
		std::size_t j)
	{
		return directional_multiply(
			grid,
			adjacent_digits,
			i,
			j,
			1,
			0);
	}

	std::size_t Largest_Product_In_A_Grid::vertical_multiply(
		const Grid& grid,
		std::size_t adjacent_digits,
		std::size_t i,
		std::size_t j)
	{

		return directional_multiply(
			grid,
			adjacent_digits,
			i,
			j,
			0,
			1);
	}

	std::size_t Largest_Product_In_A_Grid::downward_multiply(
		const Grid& grid,
		std::size_t adjacent_digits,
		std::size_t i,
		std::size_t j)
	{
		return directional_multiply(
			grid,
			adjacent_digits,
			i,
			j,
			1,
			1);
	}

	std::size_t Largest_Product_In_A_Grid::upward_multiply(
		const Grid& grid,
		std::size_t adjacent_digits,
		std::size_t i,
		std::size_t j)
	{
		return directional_multiply(
			grid,
			adjacent_digits,
			i,
			j,
			-1,
			1);
	}

	std::size_t Largest_Product_In_A_Grid::directional_multiply(
		const Grid& grid,
		std::size_t adjacent_digits,
		std::size_t i,
		std::size_t j,
		int h_direction,
		int v_direction)
	{
		if (i + (adjacent_digits - 1) * v_direction >= grid.size()
		   || j + (adjacent_digits - 1) * h_direction >= grid.size())
		{
			return 0;
		}

		std::size_t sum = 1;
		for (std::size_t k = 0; k < adjacent_digits; ++k)
		{
			sum *= grid[i + k * v_direction][j + k * h_direction];;
		}
		return sum;
	}
}
