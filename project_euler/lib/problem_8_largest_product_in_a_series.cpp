#include "problem_8_largest_product_in_a_series.hpp"

#include <vector>
#include <sstream>
#include <numeric>
#include <cassert>

namespace project_euler
{
	/**
	 * Brute force methods which scans the series and calculates the
	 * product of a substring of characters. The product calculation is
	 * thrown away when a zero is encountered.
	 */
	std::size_t Largest_Product_In_A_Series::Naive(const std::string& series, std::size_t digit_count)
	{
		std::size_t largest = 0;
		std::size_t running_total = 1;
		std::size_t running_digits = 0;
		for (std::size_t i = 0; i < series.size(); ++i)
		{
			char element = series[i];
			if (element < '0' || element > '9')
			{
				assert(false && "This function assumes that all elements are digits");
				return 0;
			}

			std::size_t number = element - '0';
			if (number == 0)
			{
				running_total = 1;
				running_digits = 0;
			}
			else
			{
				running_total *= number;
				running_digits += 1;
			}

			if (running_digits == digit_count)
			{
				largest = std::max(running_total, largest);

				std::size_t removed_number = series[i - (digit_count - 1)] - '0';
				running_total /= removed_number;
				running_digits -= 1;
			}
		}
		return largest;
	}
}
