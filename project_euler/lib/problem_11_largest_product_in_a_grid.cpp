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
				max = std::max(max, directional_multiply(grid, adjacent_digits, i, j, 1, 0)); // horizontal
				max = std::max(max, directional_multiply(grid, adjacent_digits, i, j, 0, 1)); // vertical
				max = std::max(max, directional_multiply(grid, adjacent_digits, i, j, 1, 1)); // right down
				max = std::max(max, directional_multiply(grid, adjacent_digits, i, j, 1, -1)); // right up
			}
		}
		return max;
	}

	std::size_t Largest_Product_In_A_Grid::Optimized(
			const std::string& grid_string,
			std::size_t adjacent_digits)
	{
		Grid grid = read_grid(grid_string);
		std::size_t max = 0;
		for (std::size_t i = 0; i < grid.size(); ++i)
		{
			max = std::max(max, continious_multiply(grid, adjacent_digits, i, 0, 1, 0)); // horizontal
			max = std::max(max, continious_multiply(grid, adjacent_digits, 0, i, 0, 1)); // vertical
			max = std::max(max, continious_multiply(grid, adjacent_digits, i, 0, 1, 1)); // right down
			max = std::max(max, continious_multiply(grid, adjacent_digits, i, 0, 1, -1)); // right up
			max = std::max(max, continious_multiply(grid, adjacent_digits, grid.size() - 1, i, -1, 1)); // left down
			max = std::max(max, continious_multiply(grid, adjacent_digits, grid.size() - 1, i, -1, -1)); // left up
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

	/**
	 * We first accumulate the sum using addition so that reducing the cell
	 * again can be done with subtraction instead of division which is much
	 * faseter. Then multiplication is done later because that what the 
	 * function should return.
	 */
	std::size_t Largest_Product_In_A_Grid::continious_multiply(
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

		std::size_t max = 0;
		std::size_t sum = 0;
		std::size_t digit_count = 0;
		std::size_t max_i = i;
		std::size_t max_j = j;
		while (i < grid.size() && j < grid.size())
		{
			std::size_t number = grid[i][j];
			if (number != 0)
			{
				sum += grid[i][j];
				digit_count++;
			}
			else
			{
				sum = 0;
				digit_count = 0;
			}

			i += v_direction;
			j += h_direction;

			if (digit_count == adjacent_digits)
			{
				if (max < sum)
				{
					max_i = i - adjacent_digits * v_direction;
					max_j = j - adjacent_digits * h_direction;
				}
				sum -= grid[i - adjacent_digits * v_direction][j - adjacent_digits * h_direction];
				digit_count--;
			}
		}

		std::size_t max_sum = 1;
		for (std::size_t k = 0; k < adjacent_digits; ++k)
		{
			max_sum *= grid[max_i + k * v_direction][max_j + k * h_direction];;
		}
		return max_sum;
	}
}
